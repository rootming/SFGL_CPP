#ifndef SURFACE_H
#define SURFACE_H
#include "drawdef.h"
#include "fbdev.h"

class SFGLSurface : virtual public SFGLDATA
{
public:
    SFGLSurface(int32_t w = 0, int32_t h = 0, SFGLDATA *parent = 0);
    ~SFGLSurface();
    void setColor(SFGLColor &color);
    void update(void);
    int trylock() { return pthread_mutex_trylock(&mutex); }


private:
//    SFGLCOLORMODE colormode;	//图层色彩模式
//    SFGLTRANSPRENT transprent;	//图层透明开关
//    SFGLSURFACELOCK lock;		//图层锁
//    SFGLSURFACETYPE type;		//图层类型
    pthread_mutex_t mutex;
    uint8_t alpha;	//图层alpha值
    int32_t linelen;	//行像素占用内存
    vector<SFGLDATA *> surfaceStack;
    void look(){ pthread_mutex_lock(&mutex); }
    void unlook(){ pthread_mutex_unlock(&mutex); }
};


#endif // SURFACE_H
