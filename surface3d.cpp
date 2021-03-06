#include <cmath>
#include <cstring>
#include <algorithm>
#include "surface3d.h"
#include "basedraw.h"
#include "debug.h"

//#define ROUND(x)	(x >= 0 ? (long)(x + 0.5) : (long)(x - 0.5))

//Display *display = 0;

using namespace std;

SFGLSurface3D::Buffer::~Buffer(void)
{
	delete [] data;
	delete [] depth;
}

void SFGLSurface3D::Buffer::resize(const int w, const int h)
{
	width = w;
	height = h;
	delete [] data;
	delete [] depth;
	data = new uint32_t[bytes() / sizeof(uint32_t)];
	depth = new float[bytes() / sizeof(uint32_t)];
	for (uint32_t i = 0; i < bytes() / sizeof(uint32_t); i++)
		*(depth + i) = -1.f;
}

SFGLSurface3D::SFGLSurface3D(const int width, const int height)
{
    SFGLData::buffer = NULL;
    SFGLData::resize(width, height);
	resize(width, height);
}

void SFGLSurface3D::resize(const int width, const int height)
{
	buffer.resize(width, height);
	data.mapping = Matrix4x4();
	data.mapping.translate(Vector3D(width / 2, height / 2, 0.f));
	data.mapping.scale(Vector3D(width / 2, -height / 2, -1.f));
	data.updateMVP();
}

void SFGLSurface3D::clear(void)
{
	memset(buffer.data, 0, buffer.bytes());
	for (uint32_t i = 0; i < buffer.bytes() / sizeof(uint32_t); i++)
		*(buffer.depth + i) = -INFINITY;
}

#include <iostream>
inline void SFGLSurface3D::plot(int x, int y, bool reverse, float depth, const Vector3D& colour)
{
	if (reverse)
		swap(x, y);
    if (x < 0 || y < 0 || x >= getWidth() || y >= getHeight() || depth > 0)
		return;
	if (depth < -1 || depth >= 0)
		return;
	//cout << depth << endl;
    if (*(buffer.depth + y * getWidth() + x) <= depth) {
        *(buffer.data + y * getWidth() + x) = colour.toColour();
        *(buffer.depth + y * getWidth() + x) = depth;
	}
}

void SFGLSurface3D::drawPoint(uint32_t index)
{
	const Vector3D v = map(vertex(index));
	int x = v.x(), y = v.y(), z = v.z();
	//uint32_t c = colour(index).toColour();
	uint32_t s = pointSize();
	for (uint32_t dy = 0; dy < s; dy++)
		for (uint32_t dx = 0; dx < s; dx++)
			plot(x++, y++, false, z, colour(index));
            /*if (x >= 0 && x < getWidth() && y >= 0 && y < getHeight()) {
                *(buffer.depth + y * getWidth() + x) = z;
                *(buffer.data + y++ * getWidth() + x++) = c;
			}*/
}

void SFGLSurface3D::drawArray(DrawModes mode, uint32_t first, uint32_t count)
{
	uint32_t i;
	switch (mode) {
	case Points:
		while (count--)
			drawPoint(first++);
		break;
	case LineStrip:
		if (count < 2)
			break;
		count--;
		while (count--) {
			drawLine(first, first + 1);
			first++;
		}
		break;
	case LineLoop:
		if (count < 2)
			break;
		i = first;
		count--;
		while (count--) {
			drawLine(first, first + 1);
			first++;
		}
		drawLine(i, first);
		break;
	case Lines:
		for (; count > 1; count -= 2) {
			drawLine(first, first + 1);
			first += 2;
		}
		break;
	case TriangleStrip:
		if (count < 3)
			break;
		count -= 2;
		while (count--) {
			drawTriangle(first, first + 1, first + 2);
			first++;
		}
		break;
	case TriangleFan:
		if (count < 3)
			break;
		i = first;
		count -= 2;
		while (count--) {
			first++;
			drawTriangle(i, first, first + 1);
		}
		break;
	case Triangles:
		for (; count > 2; count -= 3) {
			drawTriangle(first, first + 1, first + 2);
			first += 3;
		}
		break;
	}
}

const Vector3D SFGLSurface3D::map(const Vector4D& v)
{
	return Vector3D(data.mvp * v);
}

//#include <iostream>
void SFGLSurface3D::drawLine(uint32_t index1, uint32_t index2)
{
	// Symmetric Double Step
	Vector3D v1 = map(vertex(index1)), v2 = map(vertex(index2));
	int a1 = round(v1.x()), b1 = round(v1.y());
	int a2 = round(v2.x()), b2 = round(v2.y());
	/*// Drawing area limit
	if (a1 < 0) {
		if (a2 < 0)
			return;
		a1 = 0;
		b1 = (v2.y() - v1.y()) * (0.5f - v1.x()) / (v2.x() - v1.x()) + v1.y();
	}
	if (a2 < 0) {
		a2 = 0;
		b2 = (v1.y() - v2.y()) * (0.5f - v2.x()) / (v1.x() - v2.x()) + v2.y();
	}
    if (a1 >= getWidth()) {
        if (a2 >= getWidth())
			return;
        a1 = getWidth() - 1;
		b1 = (v2.y() - v1.y()) * (v1.x() - ((float)a1 + 0.5)) / (v1.x() - v2.x()) + v1.y();
	}
    if (a2 >= getWidth()) {
        a2 = getWidth() - 1;
		b2 = (v1.y() - v2.y()) * (v2.x() - ((float)a2 + 0.5)) / (v2.x() - v1.x()) + v2.y();
	}
	if (b1 < 0.f) {
		if (b2 < 0.f)
			return;
		b1 = 0;
		a1 = (v2.x() - v1.x()) * (0.5f - v1.y()) / (v2.y() - v1.y()) + v1.x();
	}
	if (b2 < 0.f) {
		b2 = 0;
		a2 = (v1.x() - v2.x()) * (0.5f - v2.y()) / (v1.y() - v2.y()) + v2.x();
	}
    if (b1 >= getHeight()) {
        if (b2 >= getHeight())
			return;
        b1 = getHeight() - 1;
		a1 = (v2.x() - v1.x()) * (v1.y() - ((float)b1 + 0.5)) / (v1.y() - v2.y()) + v1.x();
	}
    if (b2 >= getHeight()) {
        b2 = getHeight() - 1;
		a2 = (v1.x() - v2.x()) * (v2.y() - ((float)b2 + 0.5)) / (v2.y() - v1.y()) + v2.x();
	}
	cout << "LineF: " << v1.x() << ' ' << v1.y() << ", " << v2.x() << ' ' << v2.y() << endl;
	cout << "LineI: " << a1 << ' ' << b1 << ", " << a2 << ' ' << b2 << endl;*/
	int dx, dy, incr1, incr2, d, x, y, xend, c, pixels_left;
	int x1, y1;
	int sign_x, sign_y, step, reverse, i;
	float df, xs, z, dz;
	Vector3D clr, dclr;

	sign_x = (a2 - a1) < 0 ? -1 : 1;
	dx = (a2 - a1) * sign_x;
	sign_y = (b2 - b1) < 0 ? -1 : 1;
	dy = (b2 - b1) * sign_y;
	// Decide increment sign by the slope sign
	if (sign_x == sign_y)
		step = 1;
	else
		step = -1;

	// Choose axis of greatest movement (make * dx)
	if (dy > dx) {
		swap(a1, b1);
		swap(a2, b2);
		swap(dx, dy);
		reverse = 1;
	} else
		reverse = 0;
	// Note! Error check for dx == 0 should be included here
	// Start from the smaller coordinate
	if (a1 > a2) {
		x = a2;
		xs = reverse ? v2.y() : v2.x();
		y = b2;
		x1 = a1;
		y1 = b1;
		z = v2.z();
		dz = v1.z() - z;
		clr = colour(index2);
		dclr = colour(index1) - clr;
	} else {
		x = a1;
		xs = reverse ? v1.y() : v1.x();
		y = b1;
		x1 = a2;
		y1 = b2;
		z = v1.z();
		dz = v2.z() - z;
		clr = colour(index1);
		dclr = colour(index2) - clr;
	}

	// Note! dx = n implies 0 - n or (dx + 1) pixels to be set
	// Go round loop dx / 4 times then plot last 0, 1, 2 or 3 pixels
	// In fact (dx - 1) / 4 as 2 pixels are already plotted
	xend = (dx - 1) / 4;
	// Number of pixels left over at the end
	pixels_left = (dx - 1) % 4;
	plot(x, y, reverse, z, clr);
	// Plot only one pixel for zero length vectors
	if (pixels_left < 0)
		return;

	// Plot first two pints
	plot(x1, y1, reverse, z + dz, clr + dclr);
	incr2 = 4 * dy - 2 * dx;
	// Slope less than 1/2
	if (incr2 < 0) {
		c = 2 * dy;
		incr1 = 2 * c;
		d = incr1 - dx;
		
		for (i = 0; i < xend; i++) {	// Plotting loop
			++x;
			--x1;
			if (d < 0) {
				// Pattern 1 forwards
				df = x - xs;
				plot(x, y, reverse, z + dz * df / dx, clr + dclr * df / dx);
				df = ++x - xs;
				plot(x, y, reverse, z + dz * df / dx, clr + dclr * df / dx);
				// Pattern 1 backwards
				df = x1 - xs;
				plot(x1, y1, reverse, z + dz * df / dx, clr + dclr * df / dx);
				df = --x1 - xs;
				plot(x1, y1, reverse, z + dz * df / dx, clr + dclr * df / dx);
				d += incr1;
			} else {
				if (d < c) {
					// Pattern 2 forwards
					df = x - xs;
					plot(x, y, reverse, z + dz * df / dx, clr + dclr * df / dx);
					df = ++x - xs;
					plot(x, y += step, reverse, z + dz * df / dx, clr + dclr * df / dx);
					// Pattern 2 backwards
					df = x1 - xs;
					plot(x1, y1, reverse, z + dz * df / dx, clr + dclr * df / dx);
					df = --x1 - xs;
					plot(x1, y1 -= step, reverse, z + dz * df / dx, clr + dclr * df / dx);
				} else {
					// Pattern 3 forwards
					df = x - xs;
					plot(x, y += step, reverse, z + dz * df / dx, clr + dclr * df / dx);
					df = ++x - xs;
					plot(x, y, reverse, z + dz * df / dx, clr + dclr * df / dx);
					// Pattern 3 backwards
					df = x1 - xs;
					plot(x1, y1 -= step, reverse, z + dz * df / dx, clr + dclr * df / dx);
					df = --x1 - xs;
					plot(x1, y1, reverse, z + dz * df / dx, clr + dclr * df / dx);
				}
				d += incr2;
			}
		}

		// Plot last pattern
		if (pixels_left) {
			if (d < 0) {
				// Pattern 1
				df = ++x - xs;
				plot(x, y, reverse, z + dz * df / dx, clr + dclr * df / dx);
				if (pixels_left > 1) {
					df = ++x - xs;
					plot(x, y, reverse, z + dz * df / dx, clr + dclr * df / dx);
				}
				if (pixels_left > 2) {
					df = --x1 - xs;
					plot(x1, y1, reverse, z + dz * df / dx, clr + dclr * df / dx);
				}
			} else {
				if (d < c) {
					// Pattern 2
					df = ++x - xs;
					plot(x, y, reverse, z + dz * df / dx, clr + dclr * df / dx);
					if (pixels_left > 1) {
						df = ++x - xs;
						plot(x, y += step, reverse, z + dz * df / dx, clr + dclr * df / dx);
					}
					if (pixels_left > 2) {
						df = --x1 - xs;
						plot(x1, y1, reverse, z + dz * df / dx, clr + dclr * df / dx);
					}
				} else {
					// Pattern 3
					df = ++x - xs;
					plot(x, y += step, reverse, z + dz * df / dx, clr + dclr * df / dx);
					if (pixels_left > 1) {
						df = ++x - xs;
						plot(x, y, reverse, z + dz * df / dx, clr + dclr * df / dx);
					}
					if (pixels_left > 2) {
						df = --x1 - xs;
						plot(x1, y1 -= step, reverse, z + dz * df / dx, clr + dclr * df / dx);
					}
				}
			}
		}
	} else {
		// Slope greater than 1/2
		c = 2 * (dy - dx);
		incr1 = 2 * c;
		d = incr1 + dx;
		
		for (i = 0; i < xend; i++) {	// Plotting loop
			++x;
			--x1;
			if (d > 0) {
				// Pattern 4 forwards
				df = x - xs;
				plot(x, y += step, reverse, z + dz * df / dx, clr + dclr * df / dx);
				df = ++x - xs;
				plot(x, y += step, reverse, z + dz * df / dx, clr + dclr * df / dx);
				// Pattern 4 backwards
				df = x1 - xs;
				plot(x1, y1 -= step, reverse, z + dz * df / dx, clr + dclr * df / dx);
				df = --x1 - xs;
				plot(x1, y1 -= step, reverse, z + dz * df / dx, clr + dclr * df / dx);
				d += incr1;
			} else {
				if (d < c) {
					// Pattern 2 forwards
					df = x - xs;
					plot(x, y, reverse, z + dz * df / dx, clr + dclr * df / dx);
					df = ++x - xs;
					plot(x, y += step, reverse, z + dz * df / dx, clr + dclr * df / dx);
					// Pattern 2 backwards
					df = x1 - xs;
					plot(x1, y1, reverse, z + dz * df / dx, clr + dclr * df / dx);
					df = --x1 - xs;
					plot(x1, y1 -= step, reverse, z + dz * df / dx, clr + dclr * df / dx);
				} else {
					// Pattern 3 forwards
					df = x - xs;
					plot(x, y += step, reverse, z + dz * df / dx, clr + dclr * df / dx);
					df = ++x - xs;
					plot(x, y, reverse, z + dz * df / dx, clr + dclr * df / dx);
					// Pattern 3 backwards
					df = x1 - xs;
					plot(x1, y1 -= step, reverse, z + dz * df / dx, clr + dclr * df / dx);
					df = --x1 - xs;
					plot(x1, y1, reverse, z + dz * df / dx, clr + dclr * df / dx);
				}
				d += incr2;
			}
		}

		// Plot last pattern
		if (pixels_left) {
			if (d > 0) {
				// Pattern 4
				df = ++x - xs;
				plot(x, y += step, reverse, z + dz * df / dx, clr + dclr * df / dx);
				if (pixels_left > 1) {
					df = ++x - xs;
					plot(x, y += step, reverse, z + dz * df / dx, clr + dclr * df / dx);
				}
				if (pixels_left > 2) {
					df = --x1 - xs;
					plot(x1, y1 -= step, reverse, z + dz * df / dx, clr + dclr * df / dx);
				}
			} else {
				if (d < c) {
					// Pattern 2
					df = ++x - xs;
					plot(x, y, reverse, z + dz * df / dx, clr + dclr * df / dx);
					if (pixels_left > 1) {
						df = ++x - xs;
						plot(x, y += step, reverse, z + dz * df / dx, clr + dclr * df / dx);
					}
					if (pixels_left > 2) {
						df = --x1 - xs;
						plot(x1, y1, reverse, z + dz * df / dx, clr + dclr * df / dx);
					}
				} else {
					// Pattern 3
					df = ++x - xs;
					plot(x, y += step, reverse, z + dz * df / dx, clr + dclr * df / dx);
					if (pixels_left > 1) {
						df = ++x - xs;
						plot(x, y, reverse, z + dz * df / dx, clr + dclr * df / dx);
					}
					if (pixels_left > 2) {
						df = --x1 - xs;
						if (d > c)	// Step 3
							plot(x1, y1 -= step, reverse, z + dz * df / dx, clr + dclr * df / dx);
						else		// Step 2
							plot(x1, y1, reverse, z + dz * df / dx, clr + dclr * df / dx);
					}
				}
			}
		}
	}
}

void SFGLSurface3D::drawTriangle(uint32_t index1, uint32_t index2, uint32_t index3)
{
	Vector3D v1 = map(vertex(index1)), v2 = map(vertex(index2)), v3 = map(vertex(index3));
#if 0
	Vector3D v1 = data.modelView * vertex(index1), v2 = data.modelView * vertex(index2), v3 = data.modelView * vertex(index3);
	cout << "After modelView:" << endl;
	cout << "V1, X: " << v1.x() << ", Y: " << v1.y() << ", Z: " << v1.z() << endl;
	cout << "V2, X: " << v2.x() << ", Y: " << v2.y() << ", Z: " << v2.z() << endl;
	cout << "V3, X: " << v3.x() << ", Y: " << v3.y() << ", Z: " << v3.z() << endl;
	v1 = data.projection * v1, v2 = data.projection * v2, v3 = data.projection * v3;
	cout << "After projection:" << endl;
	cout << "V1, X: " << v1.x() << ", Y: " << v1.y() << ", Z: " << v1.z() << endl;
	cout << "V2, X: " << v2.x() << ", Y: " << v2.y() << ", Z: " << v2.z() << endl;
	cout << "V3, X: " << v3.x() << ", Y: " << v3.y() << ", Z: " << v3.z() << endl;
	v1 = data.mapping * v1, v2 = data.mapping * v2, v3 = data.mapping * v3;
	cout << "After mapping:" << endl;
	cout << "V1, X: " << v1.x() << ", Y: " << v1.y() << ", Z: " << v1.z() << endl;
	cout << "V2, X: " << v2.x() << ", Y: " << v2.y() << ", Z: " << v2.z() << endl;
	cout << "V3, X: " << v3.x() << ", Y: " << v3.y() << ", Z: " << v3.z() << endl;
#endif
	// swap to clockwise order, with index1 at the top
	if (v1.y() > v2.y()) {
		swap(v1, v2);
		swap(index1, index2);
	}
	if (v1.y() > v3.y()) {
		swap(v1, v3);
		swap(index1, index3);
	}
	// Note! y-axis is inverted
	// Check gradient for swap index2, index3
	if ((v2 - v1).normalized().x() > (v3 - v1).normalized().x()) {
		swap(v2, v3);
		swap(index2, index3);
	}
	float dx12 = v2.x() - v1.x(), dx13 = v3.x() - v1.x(), dx23 = v3.x() - v2.x();
	float dy12 = v2.y() - v1.y(), dy13 = v3.y() - v1.y(), dy23 = v3.y() - v2.y();
	float dz12 = v2.z() - v1.z(), dz13 = v3.z() - v1.z(), dz23 = v3.z() - v2.z();
	Vector3D c1 = colour(index1), c2 = colour(index2), c3 = colour(index3);
	Vector3D dc12 = c2 - c1, dc13 = c3 - c1, dc23 = c3 - c2;
	Vector3D cL, cR;
	int y, yu, yd;
	float dy, dyL, dyR;
	float xL, xR;
	float zL, zR;
	float fL, fR;
	if (dy23 >= 0) {
		// v2 above v3
		yu = round(v2.y()) - 1;
		yd = round(v3.y()) - 1;
	} else {
		// v2 below v3
		yu = round(v3.y()) - 1;
		yd = round(v2.y()) - 1;
	}
	// Upper part
	y = round(v1.y());
	if (y < 0)
		y = 0;
    for (; y <= yu && y < getHeight(); y++) {
		dy = (float)y + 0.5 - v1.y();
		fL = dy / dy12;
		fR = dy / dy13;
		xL = fL * dx12 + v1.x();
		xR = fR * dx13 + v1.x();
		if (round(xL) == round(xR))	// (round(xL) > round(xR) - 1)
			continue;
		zL = fL * dz12 + v1.z();
		zR = fR * dz13 + v1.z();
		cL = fL * dc12 + c1;
		cR = fR * dc13 + c1;
		drawScanline(y, xL, xR, zL, zR, cL, cR);
	}
	// Lower part
	if (dy23 >= 0) {
		// v2 above v3
        for (; y <= yd && y < getHeight(); y++) {
			dyL = (float)y + 0.5 - v2.y();
			dyR = (float)y + 0.5 - v1.y();
			fL = dyL / dy23;
			fR = dyR / dy13;
			xL = fL * dx23 + v2.x();
			xR = fR * dx13 + v1.x();
			if (round(xL) == round(xR))
				continue;
			zL = fL * dz23 + v2.z();
			zR = fR * dz13 + v1.z();
			cL = fL * dc23 + c2;
			cR = fR * dc13 + c1;
			drawScanline(y, xL, xR, zL, zR, cL, cR);
		}
	} else {
		// v3 above v2
        for (; y <= yd && y < getHeight(); y++) {
			dyL = (float)y + 0.5 - v1.y();
			dyR = (float)y + 0.5 - v3.y();
			fL = dyL / dy12;
			fR = dyR / -dy23;
			xL = fL * dx12 + v1.x();
			xR = fR * -dx23 + v3.x();
			if (round(xL) == round(xR))
				continue;
			zL = fL * dz12 + v1.z();
			zR = fR * -dz23 + v3.z();
			cL = fL * dc12 + c1;
			cR = fR * -dc23 + c3;
			drawScanline(y, xL, xR, zL, zR, cL, cR);
		}
	}
}

void SFGLSurface3D::drawScanline(int y, float xL, float xR, float zL, float zR, const Vector3D& cL, const Vector3D& cR)
{
	int x1 = round(xL), x2 = round(xR) - 1;
	float dx = xR - xL, dz = zR - zL;
	Vector3D dc = cR - cL;
	float f;
	if (x1 < 0)
		x1 = 0;
    while (x1 <= x2 && x1 < getWidth()) {
		f = ((float)x1 + 0.5 - xL) / dx;
		plot(x1++, y, false, f * dz + zL, f * dc + cL);
	}
}
void SFGLSurface3D::update(void)
{
    if(Fbdev::videoDevice == NULL){
        SFGL_DEBUG_WORRY("Video device not init!\n");
    }
    memcpy(SFGLData::buffer, buffer.data, buffer.bytes());
    Fbdev::videoDevice->reDraw(*this);
    Fbdev::videoDevice->update();
}
