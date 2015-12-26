#include "drawdef.h"
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
    surfaceStack.push_back(child);
}
