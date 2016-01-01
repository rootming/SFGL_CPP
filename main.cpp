#include <iostream>
#include <ctime>
#include <cstdio>
#include <pthread.h>
#include "fbdev.h"
#include "basedraw.h"
#include "debug.h"
#include "image.h"
#include "surface3d.h"
#include "sfgl.h"

using namespace std;

int main()
{
    int w = 800;
    int h = 600;
    SFGLMain(w, h);
    SFGLSurface test(w, h);
    SFGLDraw::drawLine(test, 0, 0, 100, 100, 255, 255, 255);
    SFGLDraw::drawLine(test, 0, 100, 100, 0, 255, 255, 255);
    test.update();

    return 0;
}

