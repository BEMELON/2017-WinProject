#include "stdafx.h"
#include "Point.h"
#include "Frame.h"
#include "MenuBar.h"
Point::Point(int x,int y)
    :start_x(x),start_y(y)
{
    
}

void Point::display()
{
    getFrame()->setPen(RGB(100, 100, 100), 1);
    getFrame()->rectangle(start_x, start_y + 30, end_x - start_x, end_y - start_y - 30);
    
}

Point::~Point()
{
}
