#include "drawdef.h"
#include "debug.h"
#include "fbdev.h"
#include <iostream>


SFGLDATA::SFGLDATA()
{
    width = 0;
    height = 0;
    postx = 0;
    posty = 0;
}

void SFGLDATA::resize(const int w, const int h)
{
    width = w;
    height = h;
    if(buffer != NULL)
        delete []buffer;
    buffer = new int32_t[bytes() / sizeof(int32_t)];
}


void SFGLDATA::addChild(SFGLDATA *child)
{
#ifdef DEBUG
    SFGL_DEBUG_INFO("Add child");
#endif
    surfaceStack.push_back(child);
}

void SFGLDATA::update(void)
{
    if(Fbdev::videoDevice == NULL){
        SFGL_DEBUG_WORRY("Video device not init!\n");
    }
    Fbdev::videoDevice->reDraw(*this);
    Fbdev::videoDevice->update();
}
