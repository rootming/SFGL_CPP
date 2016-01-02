#include "drawdef.h"
#include "debug.h"
#include "fbdev.h"
#include <iostream>


SFGLData::SFGLData()
{
    width = 0;
    height = 0;
    postx = 0;
    posty = 0;
}

void SFGLData::resize(const int w, const int h)
{
    width = w;
    height = h;
    if(buffer != NULL)
        delete []buffer;
    buffer = new int32_t[bytes() / sizeof(int32_t)];
    memset(buffer, 0, bytes());
}


void SFGLData::addChild(SFGLData *child)
{
#ifdef DEBUG
    SFGL_DEBUG_INFO("Add child");
#endif
    surfaceStack.push_back(child);
}

void SFGLData::update(void)
{
    if(Fbdev::videoDevice == NULL){
        SFGL_DEBUG_WORRY("Video device not init!\n");
    }
    Fbdev::videoDevice->reDraw(*this);
    Fbdev::videoDevice->update();
}
