#include <iostream>
#include <ctime>
#include <cstdio>
#include <pthread.h>
#include "fbdev.h"
#include "basedraw.h"

using namespace std;

struct timeval start;
struct timeval now;
bool ret = false;
int times;

void *testfun(void *context){
    /*
     printf("Time start\n");
     while(ok == 0)
     usleep(1000);
     printf("Time end\n");
     */
    sleep(10);
    gettimeofday(&now, NULL);
    ret = true;
    printf("use time:%ld ms\n",
            (now.tv_sec - start.tv_sec) * 1000
                    + (now.tv_usec - start.tv_usec) / 1000);
    printf("Draw %d Pixel/s\n", times);
}


int main()
{
    pthread_t t;
    Fbdev test(1920, 1080);
    SFGLSurface screen(1920, 1080);
    srand(time(0));
    BaseDraw::drawLine(test, 0, 0, 100, 100, 255, 255, 255);
    BaseDraw::drawLine(test, 0, 100, 100, 0, 255, 255, 255);
    BaseDraw::drawRectFill(test, 100, 100, 400, 400, 255, 255, 255, 255);
    BaseDraw::drawCircleFill(test, 500, 500, 100, 100, 100, 100, 255);

    gettimeofday(&start, NULL);
    pthread_create(&t, NULL, testfun, NULL);
    while(ret == false){
        //		//DrawPixelB(ma,rand()%320,rand()%240,255,255,255,255);
        //		//DrawPixelB(ma,32,24,255,255,255,255);
        BaseDraw::drawCircleFill(test, rand() % 1920, rand() % 1080, rand() % 100,
                                 rand() % 255, rand() % 255, rand() % 255, 200);//随机产生圆
        //		//DrawRectFillB(r,rand()%250,rand()%190,rand()%250,rand()%190,rand()%255,rand()%255,rand()%255,200);
        //		//usleep(100);
        //		//MixSurface(ma, r,&post1);
        //		//DrawSurface(ma, r, &post1);
        //		//MixRect(ma, r, &post1);
        times++;
        test.update();
    }
    string testStr = "This a test.";
    SFGLPost testPost(100, 100);
    BaseDraw::drawStr(test, testStr,  testPost);
    pthread_join(t, NULL);
    return 0;
}

