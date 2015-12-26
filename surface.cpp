#include "surface.h"
#include "fbdev.h"
#include "debug.h"


SFGLSurface::SFGLSurface(int32_t w, int32_t h, SFGLDATA *parent)
{
    width = w;
    width = h;
    if(parent == 0){
        SFGL_DEBUG_INFO("Add a master surface");
        Fbdev::videoDevice->surfaceStack.push_back(this);
    }
    else{
        SFGL_DEBUG_INFO("Add a child surface");
        parent->surfaceStack.push_back(this);
    }
    alpha = 0;
    pthread_mutex_init(&mutex, NULL);
}

SFGLSurface::~SFGLSurface()
{
    pthread_mutex_destroy(&mutex);
}

void SFGLSurface::setColor(SFGLColor &color)
{
    int32_t tmp = color.r << 24 | color.g << 16 | color.b << 8 | color.a;
    for(int y = 0; y < height; y++)
        for(int x = 0; x < width; x++)
            *(buffer + y * width + x) = tmp;

}

void SFGLSurface::update(void)
{
    cout<<"Called update"<<endl;
}


