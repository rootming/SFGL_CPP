#include "surface.h"
#include "fbdev.h"
#include "debug.h"


SFGLSurface::SFGLSurface(int32_t w, int32_t h, SFGLDATA *parent)
{
    width = w;
    height = h;
    if(parent == 0){
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

SFGLSurface::~SFGLSurface()
{
    pthread_mutex_destroy(&mutex);
}

void SFGLSurface::setColor(SFGLColor &color)
{
    //lock();
    int32_t tmp = color.r << 24 | color.g << 16 | color.b << 8 | color.a;
    for(int y = 0; y < height; y++)
        for(int x = 0; x < width; x++)
            *(buffer + y * width + x) = tmp;
    //unlock();

}

void SFGLSurface::update(void)
{
    if(Fbdev::videoDevice == NULL){
        SFGL_DEBUG_WORRY("Video device not init!\n");
    }
    Fbdev::videoDevice->reDraw(*this);
    Fbdev::videoDevice->update();
}


