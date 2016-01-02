#include "sfgl.h"
#include "fbdev.h"
#include "basedraw.h"
#include "debug.h"
#include <pthread.h>
#include <cstdlib>

//namespace SFGL
//{
//static pthread_t t;
//int delay = 0;

//void *SFGLoop(void *arg)
//{
//    SFGLRect *tmp = arg;

//}

int SFGLMain(const int width, const int height)
{

  Fbdev *Video = new Fbdev(width, height);
  if(Video == NULL){
      SFGL_DEBUG_WORRY("Init video device Error!\n");
      exit(0);
    }
  return 0;
}

void SFGLResizeScreen(const int width, const int height)
{
   Fbdev::videoDevice->resize(width, height);
   Fbdev::videoDevice->update();
}

int SFGLExit(void)
{
  //if(Fbdev::videoDevice != NULL)
    //delete Fbdev::videoDevice;
  return 0;
}

//}

