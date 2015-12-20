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
//#include "basedraw.h"

using namespace  std;


class BaseDraw;

typedef struct _BaseFbdev{
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
} BaseFbdev;

class Fbdev
{
public:
    Fbdev(const int w, const int h);
    ~Fbdev();
    static Fbdev *videoDevice;
    int getWidth(void) const {return width;}
    int getHeight(void) const {return height;}
    void resize(const int w, const int h);
    void printFixedInfo();
    void printVariableInfo();
    virtual void update(void);
    friend class BaseDraw;


protected:
    int32_t width, height;
    int32_t *buffer;	//缓冲图层指针
    int32_t bytes(void) {return width * height * sizeof(int32_t);}
    vector<Fbdev> surfaceStack;


private:
    BaseFbdev data;
    int initFbdev(void);
    int closeFbdev(void);


};



#endif // FBDEV_H
