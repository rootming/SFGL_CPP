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
    SFGLDraw::drawLine(test, 0, 0, 100, 100, 255, 255, 255);
    SFGLDraw::drawLine(test, 0, 100, 100, 0, 255, 255, 255);
    SFGLDraw::drawRectFill(test, 100, 100, 400, 400, 255, 255, 255, 255);
    SFGLDraw::drawCircleFill(test, 500, 500, 100, 100, 100, 100, 255);
    SFGLDraw::drawStr(test, testStr, testPost);
    //SFGLImage image(string("test.png"), &test);
    test.update();
    test.resize(1920, 1080);
    sleep(3);
    gettimeofday(&start, NULL);
    pthread_create(&t, NULL, testfun, &delay);
    ret = false;
    while(ret == false){
        SFGLDraw::drawLine(test, rand() % w, rand() % h, rand() % w, rand() % h,
                                 rand() % 255, rand() % 255, rand() % 255, 100);//随机产生圆
        times++;
        test.update();
    }
    pthread_create(&t, NULL, testfun, &delay);
    ret = false;
    while(ret == false){
        SFGLDraw::drawCircleFill(test, rand() % w, rand() % h, rand() % 100,
                                 rand() % 255, rand() % 255, rand() % 255, 100);//随机产生圆
        times++;
        test.update();
    }
    pthread_create(&t, NULL, testfun, &delay);
    ret = false;
    while(ret == false){
        SFGLDraw::drawSquareFill(test, rand() % w, rand() % h, rand() % 100,
                                 rand() % 255, rand() % 255, rand() % 255, 100);
        times++;
        test.update();
    }
    return 0;
}

