#ifndef DRAWDEF
#define DRAWDEF

#include <stdint.h>
#include <vector>

#define PI	3.14159265358979

using namespace std;



//绘图部分数据类型定义
//#define TRANSPRENT 1
//#define NTRANSPRENT 0
//#define LOCKED 1
//#define UNLOCK 0

//typedef bool SFGLTRANSPRENT
/* 透明定义 */
typedef enum _SFGLTRANSPRENT{
    NTRANSPRENT = 10, TRANSPRENT = 20
} SFGLTRANSPRENT;

/* 图层锁 */
typedef enum _SFGL_SURFACELOCK{
    LOCKED = 10, UNLOCK = 20
} SFGLSURFACELOCK;

/* 颜色模式 */
typedef enum _SFGLCOLORMODE{
    MODERGB = 10, MODERGBA = 20
} SFGLCOLORMODE;

/* 图层类型 */
typedef enum _SFGL_SURFACETYPE{
    GENERAL = 10, SCREEN = 20
} SFGLSURFACETYPE;

typedef enum _SFGL_COLOR{
    RED, GREEN, BLUE, ALPHA,
} SFGLCOLOR;

//typedef struct _SFGL_ColorRGBA{
//    uint8_t r;
//    uint8_t g;
//    uint8_t b;
//    uint8_t a;
//} SFGLColorRGBA;

//typedef struct _SFGL_ColorRGB{
//    uint8_t r;
//    uint8_t g;
//    uint8_t b;
//} SFGLColorRGB;

class SFGLDraw;
class SFGLSurface;
class Fbdev;

class SFGLData
{
public:
    SFGLData();
    //SFGLData(const SFGLData &);
    int getWidth(void) const { return width; }
    int getHeight(void) const { return height; }
    int getPostx(void) const { return postx; }
    int getPosty(void) const { return posty; }
    void setPostx(const int32_t x){ postx = x; }
    void setPosty(const int32_t y){ posty = y; }
    void setFather(SFGLData *parent){ father = parent; }
    virtual void resize(const int w, const int h);
    virtual void update(void);
    virtual void addChild(SFGLData *child = 0);
    friend class SFGLDraw;
    friend class SFGLSurface;
    friend class Fbdev;
protected:
    int32_t width, height;
    int32_t postx, posty;
    int8_t depth;
    int32_t *buffer;	//缓冲图层指针
    SFGLData *father;
    int32_t bytes(void) const {return width * height * sizeof(int32_t);}
    vector <SFGLData *> surfaceStack;

};

struct SFGLColor
{
    SFGLColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 0)
    {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    }
    SFGLColor() :r(0), g(0), b(0), a(0){}
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
} ;


struct SFGLPost
{
    SFGLPost(int32_t x, int32_t y)
    {
        this->x = x;
        this->y = y;
    }

    int32_t x;
    int32_t y;
    //int32_t seek;
};

struct SFGLRect
{
    SFGLRect(int32_t x, int32_t y, int32_t w, int32_t h)
    {
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
    }

    int32_t x;
    int32_t y;
    int32_t w;
    int32_t h;
};

struct SFGLPixel:public SFGLPost, SFGLColor
{
    SFGLPixel(int32_t x, int32_t y, uint8_t r, uint8_t g, uint8_t b, uint8_t a = 0)
        :SFGLPost(x, y), SFGLColor(r, g, b, a) {}
};



#endif // DRAWDEF

