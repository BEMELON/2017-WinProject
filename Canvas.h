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
	//Frame * m_frame;
	//void setFrame(Frame *);
	void onMouseDown(int x, int y);
    void onMouseUp(int x, int y);
	void display();
    list<Point *> m_list;
    //list<Point *>::reverse_iterator re_list;
    //Point *m_Point[100];
};

