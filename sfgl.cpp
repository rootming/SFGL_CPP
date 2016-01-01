#include "sfgl.h"
#include "fbdev.h"
#include "basedraw.h"
#include "debug.h"
#include <pthread.h>
#include <cstdlib>

//static pthread_t t;
int delay = 0;

//void *SFGLoop(void *arg)
//{
//    SFGLRect *tmp = arg;

//}

int SFGLMain(const int width, const int height, const int fps)
{

     Fbdev *Video = new Fbdev(width, height);
     if(Video == NULL){
         SFGL_DEBUG_WORRY("Init video device Error!\n");
         exit(0);
     }

}

int SFGLExit()
{
    if(Fbdev::videoDevice != NULL)
        delete Fbdev::videoDevice;
    return 0;
}

