#include "surface.h"
#include "basedraw.h"
#include "fbdev.h"
#include "debug.h"


SFGLSurface::SFGLSurface(int32_t w, int32_t h, SFGLData *parent, SFGLCOLORMODE mode)
{
    width = w;
    height = h;
    colormode = mode;
    setFather(parent);
    if(father == 0){
        SFGL_DEBUG_INFO("Add a master surface\n");
        Fbdev::videoDevice->addChild(this);
    }
    else{
        SFGL_DEBUG_INFO("Add a child surface\n");
        parent->addChild(this);
    }
    alpha = 0;
    buffer = NULL;
    resize(w, h);
    //pthread_mutex_init(&mutex, NULL);
}

SFGLSurface::SFGLSurface(const SFGLSurface &arg)
{
    width = arg.width;
    height = arg.height;
    colormode = arg.colormode;
    setFather(arg.father);
    if(father == 0){
        SFGL_DEBUG_INFO("Add a master surface\n");
        Fbdev::videoDevice->addChild(this);
    }
    else{
        SFGL_DEBUG_INFO("Add a child surface\n");
        father->addChild(this);
    }
    alpha = 0;
    buffer = NULL;
    resize(width, height);
    memcpy(buffer, arg.buffer, arg.bytes());

}

SFGLSurface::~SFGLSurface()
{
    //pthread_mutex_destroy(&mutex);
}

void SFGLSurface::setColor(SFGLColor &color)
{
    //lock();
    for(int y = 0; y < height; y++)
        for(int x = 0; x < width; x++)
            SFGLDraw::drawPixel(*this, x, y, color.r, color.g, color.b, color.a);
    //unlock();

}
void SFGLSurface::fillRect(SFGLRect &rect, SFGLColor &color)
{
    SFGLDraw::drawRectFill(*this, rect, color);

}

void SFGLSurface::drawSurface(SFGLSurface &arg, const int px, const int py)
{
    if(arg.buffer == NULL){
        SFGL_DEBUG_ERROR("Surface Buffer is NULL!\n");
        return;
    }
    int32_t tWidth = arg.getWidth() < getWidth() - px ?
                arg.getWidth() : getWidth() - px;
    int32_t tHeight = arg.getHeight() < getHeight() - py ?
                arg.getHeight() : getHeight() - py;
    for(int32_t y = 0; y < tHeight; y++){
            memcpy(buffer + getWidth() * py + px
                            + y * getWidth(),
                   arg.buffer + arg.getWidth() * y,
                   tWidth * sizeof(int32_t));
    }
//    int32_t tWidth = arg.getWidth() < getWidth() - arg.getPostx() ?
//                arg.getWidth() : getWidth() - arg.getPostx();
//    int32_t tHeight = arg.getHeight() < getHeight() - arg.getPosty() ?
//                arg.getHeight() : getHeight() - arg.getPosty();
//    for(int32_t y = 0; y < tHeight; y++){
//            memcpy(buffer + getWidth() * arg.getPosty() + arg.getPostx()
//                            + y * getWidth(),
//                   arg.buffer + arg.getWidth() * y,
//                   tWidth * sizeof(int32_t));
//    }
}

//void SFGLSurface::update(void)
//{
//    if(Fbdev::videoDevice == NULL){
//        SFGL_DEBUG_WORRY("Video device not init!\n");
//    }
//    Fbdev::videoDevice->reDraw(*this);
//    Fbdev::videoDevice->update();
//}


