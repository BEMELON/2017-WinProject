#pragma once
#include "Window.h"

class Point :
    public Window
{
public:
    Point(int x, int y);
    ~Point();
    int start_x, start_y;
    int end_x, end_y;
    void display();
};

