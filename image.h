#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
#include "fbdev.h"
#include "surface.h"
using namespace std;


class SFGLImage : public SFGLSurface
{
public:
    SFGLImage() = default;
    SFGLImage(string filename, SFGLDATA *parent = 0);
    int loadFile(string filename);
private:
    int loadImageFromPNG(string filename);
};

#endif // IMAGE_H
