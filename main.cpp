#include <iostream>
#include <ctime>
#include <cstdio>
#include <pthread.h>
#include "fbdev.h"
#include "basedraw.h"
#include "debug.h"
#include "image.h"
using namespace std;

struct timeval start;
struct timeval now;
bool ret = false;
int times;

void *testfun(void *wait){
    int *time = (int *)wait;
    sleep(*time);
    gettimeofday(&now, NULL);
    ret = true;
    printf("use time:%ld ms\n",
            (now.tv_sec - start.tv_sec) * 1000
                    + (now.tv_usec - start.tv_usec) / 1000);
    printf("Draw %d Pixel/s\n", times);
    return NULL;
}
void *autoUpdate(void *surface)
{
    Fbdev *fb;
    fb = (Fbdev *)surface;
    int fps = 30;
    for(;;){
        usleep(1000 / fps);
        fb->update();
    }

}

int main()
{
    int w = 800;
    int h = 600;
    int delay = 3;
    pthread_t t;

    Fbdev test(w, h);
    SFGLSurface screen(w, h);
    SFGLColor color(255, 255, 255, 255);
    screen.update();
    screen.setColor(color);
    string testStr = "This a test.";
    SFGLPost testPost(0, 0);
    srand(time(0));
    //pthread_create(&t, NULL, autoUpdate, &test);
    SFGLDraw::drawLine(test, 0, 0, 100, 100, 255, 255, 255);
    SFGLDraw::drawLine(test, 0, 100, 100, 0, 255, 255, 255);
    SFGLDraw::drawRectFill(test, 100, 100, 400, 400, 255, 255, 255, 255);
    SFGLDraw::drawCircleFill(test, 500, 500, 100, 100, 100, 100, 255);
    SFGLDraw::drawStr(test, testStr, testPost);
    //SFGLImage image(string("test.png"), &test);
    //test.update();

    w = 800;
    h = 800;
    test.setPostx(100);
    test.setPosty(100);
    test.resize(w, h);
    sleep(3);

    gettimeofday(&start, NULL);
    pthread_create(&t, NULL, testfun, &delay);
    ret = false;
    while(ret == false){
        SFGLDraw::drawLine(test, rand() % w, rand() % h, rand() % w, rand() % h,
                                 rand() % 255, rand() % 255, rand() % 255, 255);//随机产生圆
        times++;
        test.update();
    }
    pthread_create(&t, NULL, testfun, &delay);
    ret = false;
    while(ret == false){
        SFGLDraw::drawCircleFill(test, rand() % w, rand() % h, rand() % 100,
                                 rand() % 255, rand() % 255, rand() % 255, 255);//随机产生圆
        times++;
        test.update();
    }
    pthread_create(&t, NULL, testfun, &delay);
    ret = false;
    while(ret == false){
        SFGLDraw::drawSquareFill(test, rand() % w, rand() % h, rand() % 100,
                                 rand() % 255, rand() % 255, rand() % 255, 255);
        times++;
        test.update();
    }
    int boxw = 80;
    int count = 10;
    for(int y = 0; y < count; y++){
        for(int x = 0; x < count; x++){
            if(y % 2 == 1)
                if(x % 2 == 1)
                    SFGLDraw::drawRectFill(test, x * boxw, y * boxw, boxw, boxw, 255, 255, 255, 0);
                else
                    SFGLDraw::drawRectFill(test, x * boxw, y * boxw, boxw, boxw, 0, 0, 0, 0);
            else
                if(x % 2 == 1)
                    SFGLDraw::drawRectFill(test, x * boxw, y * boxw, boxw, boxw, 0, 0, 0, 0);
                else
                    SFGLDraw::drawRectFill(test, x * boxw, y * boxw, boxw, boxw, 255, 255, 255, 0);
        }
    }
    test.update();
    return 0;
}

