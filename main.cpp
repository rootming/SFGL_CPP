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
    SFGLMain(w, h);
    int delay = 3;
    pthread_t t;

    SFGLSurface test(w, h);
    SFGLSurface screen(w, h);
    SFGLSurface3D test2(w, h);
    SFGLImage image("test.png");
    SFGLColor color(155, 155, 255, 0);
    image.update();
    sleep(2);
    screen.setColor(color);
    screen.update();
    sleep(1);
    string testStr = "Rendtest.";
    SFGLPost testPost(10, 100);

    SFGLPost v1(100, 100);
    SFGLPost v2(50, 200);
    SFGLPost v3(300, 100);
    srand(time(0));

//    float r = 0.8;
//    Vector3D c(0.f, 0.f, 0.f);
//    for (double a = 0; a < 2.f * PI; a += PI * 2 / 120) {
//        Vector3D p(r * cos(a), r * sin(a), 0);
//        test2.vertices().push_back(c + p / 3);
//        test2.vertices().push_back(c + p);
//        test2.colours().push_back(Vector3D());
//        test2.colours().push_back(Vector3D());
//    }
//    test2.vertices().push_back(Vector3D());
//    test2.vertices().push_back(Vector3D(0.8, 0.8, 0.8));
//    test2.colours().push_back(Vector3D(1.f, 1.f, 1.f));
//    test2.colours().push_back(Vector3D(102.f / 255.f, 204.f / 255.f, 1.f));
//    for (int of = 0; of < 120; of++) {
//        test2.clear();
//        Matrix4x4 m;
//        test2.setModelView(m);
//        test2.drawArray(SFGLSurface3D::Lines, 240, 2);
//        m.rotate(PI * 2.f * (float)of / 120.f, Vector3D(1, -1, 0));
//        test2.setModelView(m);
//        for (int i = 0; i < 120; i++) {
//            float o = (float)((i - of + 120) % 120) / 120.f;
//            test2.colour(i * 2) = Vector3D(o, 1.f - o, 0);
//            test2.colour(i * 2 + 1) = Vector3D(0, 0, o);
//            test2.drawArray(SFGLSurface3D::Lines, i * 2, 2);
//        }
//        test2.update();
//        usleep(20000);
//    }
//        //float r = 0.8;
//        int cLines = 36;
//        Vector3D center(0.f, 0.f, 0.2);
//        for (double a = 0; a <= 2.f * PI; a += PI * 2.f / (float)cLines) {
//            Vector3D p(r * cos(a), r * sin(a), 0);
//            test2.vertices().push_back(center + p / 3.f);
//            test2.vertices().push_back(center + p);
//            test2.colours().push_back(Vector3D());
//            test2.colours().push_back(Vector3D());
//        }
//        //float r = 0.8;
//        int ck = 35;
//        test2.vertices().push_back(Vector3D());
//        test2.colours().push_back(Vector3D(0.f, 1.f, 0.f));
//        for (int i = 0; i <= ck; i++) {
//            Vector3D p(r * cos((float)i * 2.f * PI / (float)ck), r * sin((float)i * 2.f * PI / (float)ck), 0);
//            test2.vertices().push_back(Vector3D(p));
//            if (i % 2)
//                test2.colours().push_back(Vector3D(1.f, 0.f, 0.f));
//            else
//                test2.colours().push_back(Vector3D(0.f, 0.f, 1.f));
//        }

//        int ro = 360;
//        for (int of = 0; of < ro; of++) {
//            test2.clear();
//            Matrix4x4 m;
//            m.rotate(PI * 2.f * (float)of / (float)ro, Vector3D(1, 1, 0));
//            test2.setModelView(m);
//            for (int i = 0; i <= cLines; i++) {
//                float o = (float)((i + of) % cLines) / (float)cLines;
//                //test2.colour(i * 2) = Vector3D(o, 1.f - o, 0);
//                test2.colour(i * 2) = Vector3D(1.f - o, 0, 0);
//                //test2.colour(i * 2 + 1) = Vector3D(1.f - o, 1.f - o, o);
//                test2.colour(i * 2 + 1) = Vector3D(0, 0, o);
//            }
//            test2.drawArray(SFGLSurface3D::TriangleStrip, 0, cLines * 2 + 2);
//            test2.drawArray(SFGLSurface3D::TriangleFan, cLines * 2 + 2, of % (ck + 1) + 2);
//            test2.update();
//            usleep(20000);
//        }
    //pthread_create(&t, NULL, autoUpdate, &test);
    SFGLDraw::drawLine(test, 0, 0, 100, 100, 255, 255, 255);
    SFGLDraw::drawLine(test, 0, 100, 100, 0, 255, 255, 255);
    SFGLDraw::drawRectFill(test, 100, 100, 400, 400, 255, 255, 255, 255);
    SFGLDraw::drawCircleFill(test, 500, 500, 100, 100, 100, 100, 255);
    SFGLDraw::drawTriangleFill(test, v1, v2, v3, color);
    SFGLDraw::drawStr(test, testStr, 400, 400);
    //SFGLImage image(string("test.png"), &test);
    test.update();

    w = 600;
    h = 600;
    test.setPostx(100);
    test.setPosty(100);
    test.resize(w, h);
    test.drawSurface(image, 150, 150);
    test.update();
    int step = 1;
    SFGLRect pos(0, 0, step, image.getHeight());
    SFGLColor color2(0, 0, 0, 0);
    sleep(3);
    for(int i = 0; i < screen.getWidth();){
        screen.fillRect(pos, color2);
        i+=step;
        pos.x = i;
        screen.drawSurface(image, i, 0);
        usleep(1000000/60);
        screen.update();
    }
//    gettimeofday(&start, NULL);
//    pthread_create(&t, NULL, testfun, &delay);
//    ret = false;
//    while(ret == false){
//        SFGLDraw::drawLine(test, rand() % w, rand() % h, rand() % w, rand() % h,
//                                 rand() % 255, rand() % 255, rand() % 255, 255);//随机产生圆
//        times++;
//        test.update();
//    }
//    pthread_create(&t, NULL, testfun, &delay);
//    ret = false;
//    while(ret == false){
//        SFGLDraw::drawCircleFill(test, rand() % w, rand() % h, rand() % 100,
//                                 rand() % 255, rand() % 255, rand() % 255, 255);//随机产生圆
//        times++;
//        test.update();
//    }

//    pthread_create(&t, NULL, testfun, &delay);
//    ret = false;
//    while(ret == false){
//        SFGLDraw::drawSquareFill(test, rand() % w, rand() % h, rand() % 100,
//                                 rand() % 255, rand() % 255, rand() % 255, 255);
//        times++;
//        test.update();
//    }
//    int boxw = 80;
//    int count = 10;
//    for(int y = 0; y < count; y++){
//        for(int x = 0; x < count; x++){
//            if(y % 2 == 1)
//                if(x % 2 == 1)
//                    SFGLDraw::drawRectFill(test, x * boxw, y * boxw, boxw, boxw, 255, 255, 255, 0);
//                else
//                    SFGLDraw::drawRectFill(test, x * boxw, y * boxw, boxw, boxw, 0, 0, 0, 0);
//            else
//                if(x % 2 == 1)
//                    SFGLDraw::drawRectFill(test, x * boxw, y * boxw, boxw, boxw, 0, 0, 0, 0);
//                else
//                    SFGLDraw::drawRectFill(test, x * boxw, y * boxw, boxw, boxw, 255, 255, 255, 0);
//        }
//    }
//    test.update();
    return 0;
}

