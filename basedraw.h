#ifndef SFGLDraw_H
#define SFGLDraw_H
#include <stdint.h>
#include <iostream>
#include "surface.h"

using namespace std;


#define BIGEDITION      0
#define LITTLEEDITION   1

#define EDITION LITTLEEDITION

#if EDITION == BIGEDITION

#define POS_START 0
#define POS_END 7

#else

#define POS_START 8
#define POS_END 16

#endif

#define GETMAX(a, b) (a) >= (b) ? (a) : (b)
#define GETMIN(a, b) (a) <= (b) ? (a) : (b)

#define _DrawPixel(surface, x, y, r,g,b) 	\
	({											\
     int32_t seek = y * surface.linelen + x * 4;	\
     surface.pixel[seek] = r;					\
     surface.pixel[seek + 1] = g;				\
     surface.pixel[seek + 2] = b;				\
	 })
//#include "base_SFGLData.h"



/*
#define GETRED		0x000000FF
#define GETGREEN	0x0000FF00
#define GETBLUE	0x00FF0000
#define GETALPHA	0xFF000000
*/

//20140103 ok
/*
   inline static void _DrawPixel(SFGLData &surface,int32_t x,int32_t y, uint8_t r,
   uint8_t g, uint8_t b)
   {
   int32_t seek = y * surface->linelen + x * 4;
   surface->pixel[seek] = r;
   surface->pixel[seek + 1] = g;
   surface->pixel[seek + 2] = b;

   }*/


class SFGLDraw
{
	public:
        SFGLDraw();
		/* 指定坐标画点 */
        static void drawPixel(SFGLData &surface, int32_t x, int32_t y, uint8_t r, uint8_t g,
                uint8_t b, uint8_t a = 0);

        static void drawPixel(SFGLData &surface, SFGLPixel &pixel);


		/* 画线函数 */
        static void drawLine(SFGLData &surface, int32_t x1, int32_t y1, int32_t x2, int32_t y2,
                uint8_t r, uint8_t g, uint8_t b, uint8_t a = 0);
        static void drawLine(SFGLData &surface, SFGLPost &post1, SFGLPost &post2,
                SFGLColor &color);

		/* 画矩形函数 */
        static void drawRect(SFGLData &surface,int32_t x, int32_t y,int32_t w, int32_t h,
                uint8_t r, uint8_t g, uint8_t b, uint8_t a = 0);

        static void drawRectFill(SFGLData &surface, int32_t x,int32_t y,int32_t w,
                int32_t h, uint8_t r, uint8_t g, uint8_t b, uint8_t a = 0);

        static void drawRect(SFGLData &surface, SFGLRect &rect, SFGLColor &color);

        static void drawRectFill(SFGLData &surface,  SFGLRect &rect, SFGLColor &color);

		/* 画正方形函数 */
        static void drawSquare(SFGLData &surface, int32_t x, int32_t y, int32_t len, uint8_t r,
                uint8_t g, uint8_t b, uint8_t a = 0);
        static void drawSquareFill(SFGLData &surface, int32_t x, int32_t y, int32_t len,
                uint8_t r, uint8_t g, uint8_t b, uint8_t a = 0);

        static void drawSquare(SFGLData &surface, int32_t x, int32_t y, int32_t len, SFGLColor &color);
        static void drawSquareFill(SFGLData &surface, int32_t x, int32_t y, int32_t len, SFGLColor &color);


		/* 画圆函数 */
        static void drawCircle(SFGLData &surface, int32_t x0, int32_t y0, int32_t rad, uint8_t r,
                uint8_t g, uint8_t b, uint8_t a = 0);
        static void drawCircleFill(SFGLData &surface, int32_t x, int32_t y, int32_t rad,
                uint8_t r, uint8_t g, uint8_t b, uint8_t a = 0);

		/* 写字符函数,只支持ASCII */
        static void drawStr(SFGLData &surface, string &str, int32_t x, int32_t y);

        static void drawStr(SFGLData &surface, string &str, SFGLPost &post);

        static void fillSurface(SFGLData &surface, uint8_t r, uint8_t g, uint8_t b, uint8_t a);

        static void fillSurface(SFGLData &surface, SFGLPixel &color);

        static void putDot(SFGLData &surface, int32_t x0, int32_t y0, int32_t x,
                           int32_t y, uint8_t r, uint8_t g, uint8_t b, uint8_t a);

        static void fillBottomFlatTriangle(SFGLData &surface, SFGLPost &v1, SFGLPost &v2, SFGLPost &v3, SFGLColor &color);

        static void fillTopFlatTriangle(SFGLData &surface, SFGLPost &v1, SFGLPost &v2, SFGLPost &v3, SFGLColor &color);

        static void drawTriangle(SFGLData &surface, SFGLPost &post1, SFGLPost &post2, SFGLPost &post3, SFGLColor &color);

        static void drawTriangleFill(SFGLData &surface, SFGLPost &post1, SFGLPost &post2, SFGLPost &post3, SFGLColor &color);



        //static SFGLPixel getColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 0);

        //static SFGLPost getPost(int32_t x, int32_t y);

        //static SFGLRect getRect(int32_t x, int32_t y, int32_t w, int32_t h);

};

#endif // SFGLDraw_H
