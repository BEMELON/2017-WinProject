#pragma once
#include "Window.h"

class Point :
    public Window
{
public:
    Point(int x, int y,int type, int color);
    ~Point();
    void setEnd(int x, int y);
    int start_x, start_y;
    int end_x, end_y;
    int m_type = 0,m_color = 0;
    int isCompleted;
    void display();
};

