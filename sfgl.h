#ifndef SFGL_H
#define SFGL_H
#include "fbdev.h"
#include "basedraw.h"
#include "debug.h"
#include "image.h"
#include "surface.h"
#include "surface3d.h"
#include "sfgllable.h"

int SFGLMain(const int width, const int height);
void SFGLResizeScreen(const int width, const int height);

#endif // SFGL_H
