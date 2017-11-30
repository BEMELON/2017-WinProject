#include "stdafx.h"
#include "Point.h"
#include "Frame.h"

Point::Point(int x,int y)
    :start_x(x),start_y(y)
{
    
}

void Point::display()
{
    getFrame()->setPen(RGB(100, 100, 100), 1);
    getFrame()->rectangle(start_x, start_y, end_x, end_y);
  
}

Point::~Point()
{
}
