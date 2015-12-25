#ifndef FBDEV_H
#define FBDEV_H
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <time.h>
#include <math.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <linux/fb.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include "drawdef.h"
//#include "surface.h"
//#include "SFGLDraw.h"

using namespace  std;


class SFGLDraw;

struct BaseFbdev{
    int fbdf;
    void *fb_mmap;		//内存地址
    char *device;		//设备名
    int32_t width;		//宽
    int32_t height;    //高
    int32_t depth;		//位深
    int32_t line_length;	//行字节
    int32_t fb_size;		//高*宽*像素点字节
    struct fb_fix_screeninfo fb_fix;
    struct fb_var_screeninfo fb_var;
} ;

class Fbdev : virtual public SFGLDATA
{
public:
    Fbdev(const int w = 0, const int h = 0);
    ~Fbdev();
    static Fbdev *videoDevice;
//    int getWidth(void) const {return width;}
//    int getHeight(void) const {return height;}
    friend class SFGLDraw;
    friend class SFGLSurface;
    static int8_t redOffset;
    static int8_t blueOffset;
    static int8_t greenOffset;
    static int8_t alphaOffset;
    void update(void);

protected:

private:
    BaseFbdev data;
    int initFbdev(void);
    int closeFbdev(void);
    void printFixedInfo();
    void printVariableInfo();


};



#endif // FBDEV_H
