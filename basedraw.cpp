#include "basedraw.h"
#include "drawdef.h"
#include "debug.h"
#include "deffont.h"
#include <cstring>


BaseDraw::BaseDraw()
{


}


void BaseDraw::drawPixel(Fbdev &surface, int32_t x, int32_t y, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    int32_t seek;
    int32_t tmp = r << 24 | g << 16 | b << 8 | a;
    seek = x + y * surface.width;
    //边缘检测
    //cout << "Draw postion:" << x << " " << y << endl;
    //cout<< surface.width << " " << surface.height << endl;
    if(x >= 0 && y >= 0 && x < surface.width && y < surface.height){
        memcpy(surface.buffer + seek, &tmp, sizeof(int32_t));
    }
    else{
        SFGL_DEBUG_WORRY("Draw Pixel out of Range!\n");
    }
}

void BaseDraw::drawPixel(Fbdev &surface, SFGLPixel &pixel)
{
    int32_t seek;
    int32_t tmp = pixel.r << 24 | pixel.g << 16 | pixel.b << 8 | pixel.a;
    seek = pixel.x + pixel.y * surface.width;
    //边缘检测
    if(pixel.x >= 0 && pixel.y >= 0 && pixel.x <= surface.width && pixel.y <= surface.height){
        memcpy(surface.buffer + seek, &tmp, sizeof(int32_t));
    }
    else{
        SFGL_DEBUG_WORRY("Draw Pixel out of Range!\n");
    }
}


/* 画线函数 */
void BaseDraw::drawLine(Fbdev &surface, int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    int32_t x_s, x_e, y_s, y_e;/* Be careful */
    int32_t bz;
    double k;	//斜率
    x_s = GetMin(x1, x2);
    y_s = GetMin(y1, y2);
    x_e = GetMax(x1, x2);
    y_e = GetMax(y1, y2);
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

void BaseDraw::drawLine(Fbdev &surface, SFGLPost &post1, SFGLPost &post2, SFGLColor &color)
{
    int32_t x_s, x_e, y_s, y_e;/* Be careful */
    int32_t bz;
    double k;	//斜率
    x_s = GetMin(post1.x, post2.x);
    y_s = GetMin(post1.y, post2.y);
    x_e = GetMax(post1.x, post2.x);
    y_e = GetMax(post1.y, post2.y);
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
void BaseDraw::drawRect(Fbdev &surface,int32_t x, int32_t y,int32_t w, int32_t h, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{

    drawLine(surface, x, y, x + w, y, r, g, b, a);
    drawLine(surface, x, y + h, x + w, y + h, r, g, b, a);
    drawLine(surface, x, y, x, y + h, r, g, b, a);
    drawLine(surface, x + w, y, x + w, y + h, r, g, b, a);
}

void BaseDraw::drawRectFill(Fbdev &surface, int32_t x,int32_t y,int32_t w, int32_t h, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    int32_t yy;
    for(yy = 0; yy <= h; yy++)
        drawLine(surface, x, y + yy, x + w, y + yy, r, g, b, a);
}

void BaseDraw::drawRect(Fbdev &surface, SFGLRect &rect, SFGLColor &color)
{
    drawRect(surface, rect.x, rect.y, rect.w, rect.h, color.r, color.g, color.b, color.a);
}

void BaseDraw::drawRectFill(Fbdev &surface,  SFGLRect &rect, SFGLColor &color)
{
    drawRectFill(surface, rect.x, rect.y, rect.w, rect.h, color.r, color.g, color.b, color.a);
}

/* 画正方形函数 */
void BaseDraw::drawSquare(Fbdev &surface, int32_t x, int32_t y, int32_t len, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    drawRect(surface, x, y, len, len, r, g, b, a);

}

void BaseDraw::drawSquareFill(Fbdev &surface, int32_t x, int32_t y, int32_t len,
        uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    drawRectFill(surface, x, y, len, len, r, g, b, a);

}

void BaseDraw::drawSquare(Fbdev &surface, int32_t x, int32_t y, int32_t len, SFGLColor &color)
{
    drawRect(surface, x, y, len, len, color.r, color.g, color.b, color.a);

}

void BaseDraw::drawSquareFill(Fbdev &surface, int32_t x, int32_t y, int32_t len, SFGLColor &color)
{
    drawRectFill(surface, x, y, len, len, color.r, color.g, color.b, color.a);

}


void BaseDraw::putDot(Fbdev &surface, int32_t x0, int32_t y0, int32_t x,
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
void BaseDraw::drawCircle(Fbdev &surface, int32_t x0, int32_t y0, int32_t rad, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
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

void BaseDraw::drawCircleFill(Fbdev &surface, int32_t x, int32_t y, int32_t rad, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    int32_t yy;
    double tmp;
    for(yy = y - rad; yy <= y + rad; yy++){
        tmp = sqrt(rad * rad - (yy - y) * (yy - y));
        drawLine(surface, x - tmp, yy, x + tmp, yy, r, g, b, a);
    }

}

/* 写字符函数,只支持ASCII */
void BaseDraw::drawStr(Fbdev &surface, string &str, int32_t x, int32_t y)
{
    SFGL_DEBUG_INFO("%s\n", str.c_str());
    int32_t ox, oy;
    int32_t c, i, l, seek, len;
    unsigned char width;

    width = 8;
    ox = x;
    oy = y;
    len = str.length();

    for(c = 0; c < len; c++){
        seek = str[c] * 10;
        if(str[c] == '\n'){
            ox = x;
            oy += 10;
            continue;
        }
        for(l = 0; l <= 9; l++){
            for(i = 0; i <= 7; i++){
                //usleep(100);
                //if(((font_bits[seek] >> (i + 8) ) & 1) == 1)
                //DrawPixel(surface, ox+8-i, oy+l, 255, 255, 255, 255);
                if(((font_bits[seek] >> i) & 1) == 1)
                    drawPixel(surface, ox - i, oy + l, 200, 200, 200, 220);
                //else
                //_DrawPixel(surface,ox+8-i,oy+l,255,255,5,255);
            }
            seek++;
        }
        ox += width;
    }

}

void BaseDraw::drawStr(Fbdev &surface, string &str, SFGLPost &post)
{
    drawStr(surface, str, post.x, post.y);

}

void BaseDraw::fillSurface(Fbdev &surface, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    for(int32_t y = 0; y < surface.height; y++)
        for(int32_t x = 0; x < surface.width; x++)
            drawPixel(surface, x, y, r, g, b, a);



}

void BaseDraw::fillSurface(Fbdev &surface, SFGLPixel &color)
{
    for(int32_t y = 0; y < surface.height; y++)
        for(int32_t x = 0; x < surface.width; x++)
            drawPixel(surface, x, y, color.r, color.g, color.b, color.a);

}


//SFGLColor getColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
//{
//    return SFGLColor(r, g, b ,a);
//}

//SFGLPost getPost(int32_t x, int32_t y)
//{
//    return SFGLPost(x, y);
//}


//SFGLRect getRect(int32_t x, int32_t y, int32_t w, int32_t h)
//{
//    return SFGLRect(x, y, w, h);
//}
