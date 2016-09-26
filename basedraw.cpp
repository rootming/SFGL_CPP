#include "basedraw.h"
#include "drawdef.h"
#include "debug.h"
#include "font.h"
#include <cstring>
#include <algorithm>

#undef SFGL_DEBUG

SFGLDraw::SFGLDraw()
{


}


void SFGLDraw::drawPixel(SFGLData &surface, int32_t x, int32_t y, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    //lock();
    int32_t seek;
    int32_t tmp = r << Fbdev::redOffset |
                       g << Fbdev::greenOffset |
                       b << Fbdev::blueOffset |
                       a << Fbdev::alphaOffset;

    seek = x + y * surface.width;
    //边缘检测
    //cout << "Draw postion:" << x << " " << y << endl;
    //cout<< surface.width << " " << surface.height << endl;
    if(x >= 0 && y >= 0 && x < surface.width && y < surface.height){
        memcpy(surface.buffer + seek, &tmp, sizeof(int32_t));
#ifdef SFGL_DEBUG
        SFGL_DEBUG_INFO("Draw Pixel!\n");
#endif
    }
    else{
#ifdef SFGL_DEBUG
        SFGL_DEBUG_WORRY("Draw Pixel out of Range!\n");
#endif
    }
    //unlock();
}

void SFGLDraw::drawPixel(SFGLData &surface, SFGLPixel &pixel)
{
    int32_t seek;
    int32_t tmp = pixel.r << 24 | pixel.g << 16 | pixel.b << 8 | pixel.a;
    seek = pixel.x + pixel.y * surface.width;
    //边缘检测
    if(pixel.x >= 0 && pixel.y >= 0 && pixel.x < surface.width && pixel.y < surface.height){
        memcpy(surface.buffer + seek, &tmp, sizeof(int32_t));
#ifdef SFGL_DEBUG
        SFGL_DEBUG_INFO("Draw Pixel!\n");
#endif
    }
    else{
#ifdef SFGL_DEBUG
        SFGL_DEBUG_WORRY("Draw Pixel out of Range!\n");
#endif
    }
}


/* 画线函数 */
void SFGLDraw::drawLine(SFGLData &surface, int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    int32_t x_s, x_e, y_s, y_e;/* Be careful */
    int32_t bz;
    double k;	//斜率
    x_s = GETMIN(x1, x2);
    y_s = GETMIN(y1, y2);
    x_e = GETMAX(x1, x2);
    y_e = GETMAX(y1, y2);
    if(y1 == y2)
        for(; x_s <= x_e; x_s++)
            drawPixel(surface, x_s, y_s, r, g, b, a);
    else if(x1 == x2)
        for(; y_s <= y_e; y_s++)
            drawPixel(surface, x_s, y_s, r, g, b, a);
    else{
        bz = y1;
        k = (double)(y2 - y1) / (double)(x2 - x1);
        for(; x_s <= x_e; x_s++)
            drawPixel(surface, x_s, (x_s - x1) * k + bz, r, g, b, a);
    }

}

void SFGLDraw::drawLine(SFGLData &surface, SFGLPost &post1, SFGLPost &post2, SFGLColor &color)
{
    int32_t x_s, x_e, y_s, y_e;/* Be careful */
    int32_t bz;
    double k;	//斜率
    x_s = GETMIN(post1.x, post2.x);
    y_s = GETMIN(post1.y, post2.y);
    x_e = GETMAX(post1.x, post2.x);
    y_e = GETMAX(post1.y, post2.y);
    if(post1.y == post2.y)
        for(; x_s <= x_e; x_s++)
            drawPixel(surface, x_s, y_s, color.r, color.g, color.b, color.a);
    else if(post1.x == post2.x)
        for(; y_s <= y_e; y_s++)
            drawPixel(surface, x_s, y_s, color.r, color.g, color.b, color.a);
    else{
        bz = post1.y;
        k = (double)(post2.y - post1.y) / (double)(post2.x - post1.x);
        for(; x_s <= x_e; x_s++)
            drawPixel(surface, x_s, (x_s - post1.x) * k + bz, color.r, color.g, color.b, color.a);
    }
}

/* 画矩形函数 */
void SFGLDraw::drawRect(SFGLData &surface,int32_t x, int32_t y,int32_t w, int32_t h, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{

    drawLine(surface, x, y, x + w, y, r, g, b, a);
    drawLine(surface, x, y + h, x + w, y + h, r, g, b, a);
    drawLine(surface, x, y, x, y + h, r, g, b, a);
    drawLine(surface, x + w, y, x + w, y + h, r, g, b, a);
}

void SFGLDraw::drawRectFill(SFGLData &surface, int32_t x,int32_t y,int32_t w, int32_t h, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    int32_t yy;
    for(yy = 0; yy <= h; yy++)
        drawLine(surface, x, y + yy, x + w, y + yy, r, g, b, a);
}

void SFGLDraw::drawRect(SFGLData &surface, SFGLRect &rect, SFGLColor &color)
{
    drawRect(surface, rect.x, rect.y, rect.w, rect.h, color.r, color.g, color.b, color.a);
}

void SFGLDraw::drawRectFill(SFGLData &surface,  SFGLRect &rect, SFGLColor &color)
{
    drawRectFill(surface, rect.x, rect.y, rect.w, rect.h, color.r, color.g, color.b, color.a);
}

/* 画正方形函数 */
void SFGLDraw::drawSquare(SFGLData &surface, int32_t x, int32_t y, int32_t len, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    drawRect(surface, x, y, len, len, r, g, b, a);

}

void SFGLDraw::drawSquareFill(SFGLData &surface, int32_t x, int32_t y, int32_t len,
                              uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    drawRectFill(surface, x, y, len, len, r, g, b, a);

}

void SFGLDraw::drawSquare(SFGLData &surface, int32_t x, int32_t y, int32_t len, SFGLColor &color)
{
    drawRect(surface, x, y, len, len, color.r, color.g, color.b, color.a);

}

void SFGLDraw::drawSquareFill(SFGLData &surface, int32_t x, int32_t y, int32_t len, SFGLColor &color)
{
    drawRectFill(surface, x, y, len, len, color.r, color.g, color.b, color.a);

}


void SFGLDraw::putDot(SFGLData &surface, int32_t x0, int32_t y0, int32_t x,
                      int32_t y, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    drawPixel(surface, x0 + x, y0 + y, r, g, b, a);
    drawPixel(surface, x0 + x, y0 - y, r, g, b, a);
    drawPixel(surface, x0 - x, y0 + y, r, g, b, a);
    drawPixel(surface, x0 - x, y0 - y, r, g, b, a);
    drawPixel(surface, x0 + y, y0 + x, r, g, b, a);
    drawPixel(surface, x0 + y, y0 - x, r, g, b, a);
    drawPixel(surface, x0 - y, y0 + x, r, g, b, a);
    drawPixel(surface, x0 - y, y0 - x, r, g, b, a);
}

/* 画圆函数 */
void SFGLDraw::drawCircle(SFGLData &surface, int32_t x0, int32_t y0, int32_t rad, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    if(x0 - r >= surface.width || y0 - r >= surface.height)
        return;
    int x, y;
    float d;
    x = 0;
    y = rad;
    d = 5.0 / 4 - r;

    while(x <= y){
        putDot(surface, x0, y0, x, y, r, g, b, a);
        if(d < 0)
            d += x * 2.0 + 1;
        else{
            d += 2.0 * (x - y) + 1;
            //d+=2.0*(x-y)+5;
            y--;
        }
        x++;
    }

}

void SFGLDraw::drawCircleFill(SFGLData &surface, int32_t x, int32_t y, int32_t rad, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    int32_t yy;
    double tmp;
    for(yy = y - rad; yy <= y + rad; yy++){
        tmp = sqrt(rad * rad - (yy - y) * (yy - y));
        drawLine(surface, x - tmp, yy, x + tmp, yy, r, g, b, a);
    }

}

/* 写字符函数,只支持ASCII */
void SFGLDraw::drawStr(SFGLData &surface, string &str, int32_t x, int32_t y, SFGLColor &color)
{
#ifdef DEBUG
    SFGL_DEBUG_INFO("%s\n", str.c_str());
#endif
    int32_t ox, oy;
    uint32_t seek, len;
    int32_t width;

    width = 8;
    ox = x;
    oy = y;
    len = str.length();
    const char *tmp = str.c_str();

    for(uint32_t c = 0; c < len; c++){
        seek = tmp[c] * 10;
        if(tmp[c] == '\n'){
            ox = x;
            oy += 10;
            continue;
        }
        for(uint32_t l = 0; l < 10; l++){
            for(uint32_t i = 0; i < 8; i++){
                if((font_bits[seek] >> i) & 0x1){
                    drawPixel(surface, ox - i, oy + l, color.r, color.g, color.b, color.a);
                    //cout<<"*";
                }
                else{
                    //cout<<" ";
                }
                //cout<<((font_bits[seek] << i) & 0x1);
                //(font_bits[seek] >> i & 0x1) ? cout <<"1" : cout <<"0";
            }
            //cout<<font_bits[seek]<<":"<<seek<<endl;
            //cout<<'\n';
           // cout<<font_bits[seek]<<endl;
            seek++;
        }
        ox += width;
    }

}

void SFGLDraw::drawStr(SFGLData &surface, string &str, SFGLPost &post, SFGLColor &color)
{
    drawStr(surface, str, post.x, post.y, color);

}

void SFGLDraw::fillSurface(SFGLData &surface, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    for(int32_t y = 0; y < surface.height; y++)
        for(int32_t x = 0; x < surface.width; x++)
            drawPixel(surface, x, y, r, g, b, a);



}

void SFGLDraw::fillSurface(SFGLData &surface, SFGLPixel &color)
{
    for(int32_t y = 0; y < surface.height; y++)
        for(int32_t x = 0; x < surface.width; x++)
            drawPixel(surface, x, y, color.r, color.g, color.b, color.a);

}

void SFGLDraw::drawTriangle(SFGLData &surface, SFGLPost &post1, SFGLPost &post2, SFGLPost &post3, SFGLColor &color)
{
    drawLine(surface, post1, post2, color);
    drawLine(surface, post1, post3, color);
    drawLine(surface, post2, post3, color);
}

void SFGLDraw::fillBottomFlatTriangle(SFGLData &surface, SFGLPost &v1, SFGLPost &v2, SFGLPost &v3, SFGLColor &color)
{
  int32_t invslope1 = (v2.x - v1.x) / (v2.y - v1.y);
  int32_t invslope2 = (v3.x - v1.x) / (v3.y - v1.y);

  int32_t curx1 = v1.x;
  int32_t curx2 = v1.x;

  for (int32_t scanlineY = v1.y; scanlineY <= v2.y; scanlineY++)
  {
    drawLine(surface, curx1, scanlineY, curx2, scanlineY, color.r, color.g, color.b, color.a);
    curx1 += invslope1;
    curx2 += invslope2;
  }
}


void SFGLDraw::fillTopFlatTriangle(SFGLData &surface, SFGLPost &v1, SFGLPost &v2, SFGLPost &v3, SFGLColor &color)
{
  int32_t invslope1 = (v3.x - v1.x) / (v3.y - v1.y);
  int32_t invslope2 = (v3.x - v2.x) / (v3.y - v2.y);

  int32_t curx1 = v3.x;
  int32_t curx2 = v3.x;

  for (int32_t scanlineY = v3.y; scanlineY > v1.y; scanlineY--)
  {
    curx1 -= invslope1;
    curx2 -= invslope2;
    drawLine(surface, curx1, scanlineY, curx2, scanlineY, color.r, color.g, color.b, color.a);
  }
}

void SFGLDraw::drawTriangleFill(SFGLData &surface, SFGLPost &post1, SFGLPost &post2, SFGLPost &post3, SFGLColor &color)
{
    /* at first sort the three vertices by y-coordinate ascending so v1 is the topmost vertice */
    vector<SFGLPost> v;
    v.push_back(post1);
    v.push_back(post2);
    v.push_back(post3);
    sort(v.begin(), v.end(), [](const SFGLPost &a, const SFGLPost &b){ return a.y < b.y;});
#ifdef SFGL_DEBUG
    for(auto it:v)
        cout << it.x << ":" << it.y << endl;
    SFGL_DEBUG_INFO("Sort postition\n");
#endif
    /* here we know that v1.y <= v2.y <= v3.y */
    /* check for trivial case of bottom-flat triangle */
    if (v[1].y == v[2].y)
    {
        fillBottomFlatTriangle(surface, v[0], v[1], v[2], color);
    }
    /* check for trivial case of top-flat triangle */
    else if (v[0].y == v[1].y)
    {
        fillTopFlatTriangle(surface, v[0], v[1], v[2], color);
    }
    else
    {
     //         (int)(vt1.x + ((float)(vt2.y - vt1.y) / (float)(vt3.y - vt1.y)) * (vt3.x - vt1.x)), vt2.y);
        /* general case - split the triangle in a topflat and bottom-flat one */
        SFGLPost v4((v[0].x + ((v[1].y - v[0].y) / (v[2].y - v[0].y)) * (v[2].x - v[0].x)), v[1].y);
        fillBottomFlatTriangle(surface, v[0], v[1], v4, color);
        fillTopFlatTriangle(surface, v[1], v4, v[2], color);
    }

}
