#pragma once
#include "Window.h"
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
    Point *m_Point[100];
};

