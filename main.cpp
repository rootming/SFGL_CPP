#include <iostream>
#include <ctime>
#include <cstdio>
#include <pthread.h>
#include <wchar.h>
#include "sfgl.h"

using namespace std;

struct timeval start;
struct timeval now;
bool ret = false;
int times;
int w = 800;
int h = 800;
int delay(3);


void testFont(const wchar_t *str);
void test3d(void);
void testNormal(void);
void testRender(void);
void testDrawBox(void);

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

int main(void)
{
	SFGLMain(w, h);
	testFont(L"TTF load test.");
	sleep(1);
	test3d();
	testNormal();
	testRender();
	testDrawBox();
	SFGLExit();
	return 0;
}

void testFont(const wchar_t *str)
{
	SFGLLable lable(str);
	lable.setFontSize(20);
	lable.setBlank(1);
	lable.setPostx(100);
	lable.setPosty(100);
	lable.initString();
	lable.update();
}

void test3d(void)
{
	testFont(L"3D Test");
	sleep(1);
	SFGLSurface3D sfgl3d(800, 600);
	float r = 0.8;
	Vector3D c(0.f, 0.f, 0.f);
	for (double a = 0; a < 2.f * PI; a += PI * 2 / 120) {
		Vector3D p(r * cos(a), r * sin(a), 0);
		sfgl3d.vertices().push_back(c + p / 3);
		sfgl3d.vertices().push_back(c + p);
		sfgl3d.colours().push_back(Vector3D());
		sfgl3d.colours().push_back(Vector3D());
	}
	sfgl3d.vertices().push_back(Vector3D());
	sfgl3d.vertices().push_back(Vector3D(0.8, 0.8, 0.8));
	sfgl3d.colours().push_back(Vector3D(1.f, 1.f, 1.f));
	sfgl3d.colours().push_back(Vector3D(102.f / 255.f, 204.f / 255.f, 1.f));
	for (int of = 0; of < 120; of++) {
		sfgl3d.clear();
		Matrix4x4 m;
		sfgl3d.setModelView(m);
		sfgl3d.drawArray(SFGLSurface3D::Lines, 240, 2);
		m.rotate(PI * 2.f * (float)of / 120.f, Vector3D(1, -1, 0));
		sfgl3d.setModelView(m);
		for (int i = 0; i < 120; i++) {
			float o = (float)((i - of + 120) % 120) / 120.f;
			sfgl3d.colour(i * 2) = Vector3D(o, 1.f - o, 0);
			sfgl3d.colour(i * 2 + 1) = Vector3D(0, 0, o);
			sfgl3d.drawArray(SFGLSurface3D::Lines, i * 2, 2);
		}
		sfgl3d.update();
		usleep(20000);
	}


}

void testNormal(void)
{
	SFGLSurface test(w, h);
	SFGLSurface screen(w, h);
	SFGLImage image("test.png");
	string testStr = "Dot font test.";
	SFGLPost testPost(10, 100);
	SFGLPost v1(100, 100);
	SFGLPost v2(50, 200);
	SFGLPost v3(300, 100);
	SFGLColor color(155, 155, 255, 0);
	image.update();
	sleep(2);
	screen.setColor(color);
	color = { 0, 0, 0, 0 };
	SFGLDraw::drawStr(screen, testStr, 200, 400, color);
	screen.update();
	sleep(2);
	srand(time(0));
	SFGLDraw::drawLine(test, 0, 0, 100, 100, 255, 255, 255);
	SFGLDraw::drawLine(test, 0, 100, 100, 0, 255, 255, 255);
	SFGLDraw::drawRectFill(test, 100, 100, 400, 400, 255, 255, 255, 255);
	SFGLDraw::drawCircleFill(test, 500, 500, 100, 100, 100, 100, 255);
	color = { 255, 125, 215, 100};
	SFGLDraw::drawTriangleFill(test, v1, v2, v3, color);
	SFGLDraw::drawStr(test, testStr, 400, 400, color);
	test.update();
	sleep(2);
	w = 600;
	h = 600;
	SFGLResizeScreen(w, h);
	test.setPostx(100);
	test.setPosty(100);
	test.resize(w, h);
	test.drawSurface(image, 150, 150);
	test.update();
	int step = 1;
	SFGLRect pos(0, 0, step, image.getHeight());
	SFGLColor color2(0, 0, 0, 0);
	testFont(L"Image move test.");
	sleep(2);
	for(int i = 0; i < screen.getWidth();){
		screen.fillRect(pos, color2);
		i+=step;
		pos.x = i;
		screen.drawSurface(image, i, 0);
		usleep(1000000/200);
		screen.update();
	}
}

void testRender(void)
{
	testFont(L"Random test.");
	SFGLSurface test(w, h);
	pthread_t t;
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
}

void testDrawBox(void)
{
	SFGLSurface test(800, 800);
	SFGLResizeScreen(800, 800);
	int boxw = 80;
	int count = 10;
	testFont(L"Draw test.");
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
}
