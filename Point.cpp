#include "stdafx.h"
#include "Point.h"
#include "Frame.h"
#include "MenuBar.h"

enum { 사각형, 타원, 선분 };
enum { 검은색, 빨간색, 파란색 };
Point::Point(int x, int y, int type, int color)
    :start_x(x), start_y(y), m_type(type), m_color(color), isCompleted(false)
{   
}

void Point::setEnd(int x, int y)
{
    end_x = x; end_y = y;
}


void Point::display()
{
    if(m_color == 검은색) getFrame()->setPen(RGB(0, 0, 0), 1);
    else if(m_color == 빨간색) getFrame()->setPen(RGB(255, 0, 0), 1);
    else if (m_color == 파란색) getFrame()->setPen(RGB(0, 0, 255), 1);
    
    if(m_type == 사각형) getFrame()->rectangle(start_x, start_y + m_MenuBar.getHeight(), end_x - start_x, end_y - start_y - m_MenuBar.getHeight());
    else if (m_type == 타원) getFrame()->ellipse(start_x, start_y + m_MenuBar.getHeight(), end_x - start_x, end_y - start_y - m_MenuBar.getHeight());
    else if (m_type == 선분) getFrame()->line(start_x, start_y + m_MenuBar.getHeight(), end_x - start_x, end_y - start_y - m_MenuBar.getHeight());
  
    
}

Point::~Point()
{
}
