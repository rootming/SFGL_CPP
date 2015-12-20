#ifndef BASEDRAW_H
#define BASEDRAW_H
#include <stdint.h>
#include <iostream>
#include "surface.h"

using namespace std;

#define GetMax(a, b) (a) >= (b) ? (a) : (b)
#define GetMin(a, b) (a) <= (b) ? (a) : (b)

#define _DrawPixel(surface, x, y, r,g,b) 	\
	({											\
     int32_t seek = y * surface.linelen + x * 4;	\
     surface.pixel[seek] = r;					\
     surface.pixel[seek + 1] = g;				\
     surface.pixel[seek + 2] = b;				\
	 })
//#include "base_fbdev.h"



/*
#define GETRED		0x000000FF
#define GETGREEN	0x0000FF00
#define GETBLUE	0x00FF0000
#define GETALPHA	0xFF000000
*/

//20140103 ok
/*
   inline static void _DrawPixel(Fbdev &surface,int32_t x,int32_t y, uint8_t r,
   uint8_t g, uint8_t b)
   {
   int32_t seek = y * surface->linelen + x * 4;
   surface->pixel[seek] = r;
   surface->pixel[seek + 1] = g;
   surface->pixel[seek + 2] = b;

   }*/


class BaseDraw
{
	public:
        BaseDraw();
		/* 指定坐标画点 */
        static void drawPixel(Fbdev &surface, int32_t x, int32_t y, uint8_t r, uint8_t g,
                uint8_t b, uint8_t a = 0);

        static void drawPixel(Fbdev &surface, SFGLPixel &pixel);


		/* 画线函数 */
        static void drawLine(Fbdev &surface, int32_t x1, int32_t y1, int32_t x2, int32_t y2,
                uint8_t r, uint8_t g, uint8_t b, uint8_t a = 0);
        static void drawLine(Fbdev &surface, SFGLPost &post1, SFGLPost &post2,
                SFGLColor &color);

		/* 画矩形函数 */
        static void drawRect(Fbdev &surface,int32_t x, int32_t y,int32_t w, int32_t h,
                uint8_t r, uint8_t g, uint8_t b, uint8_t a = 0);

        static void drawRectFill(Fbdev &surface, int32_t x,int32_t y,int32_t w,
                int32_t h, uint8_t r, uint8_t g, uint8_t b, uint8_t a = 0);

        static void drawRect(Fbdev &surface, SFGLRect &rect, SFGLColor &color);

        static void drawRectFill(Fbdev &surface,  SFGLRect &rect, SFGLColor &color);

		/* 画正方形函数 */
        static void drawSquare(Fbdev &surface, int32_t x, int32_t y, int32_t len, uint8_t r,
                uint8_t g, uint8_t b, uint8_t a = 0);
        static void drawSquareFill(Fbdev &surface, int32_t x, int32_t y, int32_t len,
                uint8_t r, uint8_t g, uint8_t b, uint8_t a = 0);

        static void drawSquare(Fbdev &surface, int32_t x, int32_t y, int32_t len, SFGLColor &color);
        static void drawSquareFill(Fbdev &surface, int32_t x, int32_t y, int32_t len, SFGLColor &color);


		/* 画圆函数 */
        static void drawCircle(Fbdev &surface, int32_t x0, int32_t y0, int32_t rad, uint8_t r,
                uint8_t g, uint8_t b, uint8_t a = 0);
        static void drawCircleFill(Fbdev &surface, int32_t x, int32_t y, int32_t rad,
                uint8_t r, uint8_t g, uint8_t b, uint8_t a = 0);

		/* 写字符函数,只支持ASCII */
        static void drawStr(Fbdev &surface, string &str, int32_t x, int32_t y);

        static void drawStr(Fbdev &surface, string &str, SFGLPost &post);

        static void fillSurface(Fbdev &surface, uint8_t r, uint8_t g, uint8_t b, uint8_t a);

        static void fillSurface(Fbdev &surface, SFGLPixel &color);

        static void putDot(Fbdev &surface, int32_t x0, int32_t y0, int32_t x,
                           int32_t y, uint8_t r, uint8_t g, uint8_t b, uint8_t a);

        //static SFGLPixel getColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 0);

        //static SFGLPost getPost(int32_t x, int32_t y);

        //static SFGLRect getRect(int32_t x, int32_t y, int32_t w, int32_t h);

};

#endif // BASEDRAW_H
