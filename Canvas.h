#pragma once
#include "Window.h"
#include <list>
using namespace std;
class Frame;
class Point;
class Canvas: public Window
{
public:
    int PointCnt = 0;
	Canvas();
	~Canvas();
	void onMouseDown(int x, int y);
    void onMouseUp(int x, int y);
    void onKeyMouseClick(int x, int y);
	void display();
    void Drag(int x, int y);
    list<Point *> m_list;
};

