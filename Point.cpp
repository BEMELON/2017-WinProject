#include "stdafx.h"
#include "Point.h"
#include "Frame.h"
#include "MenuBar.h"

enum { �簢��, Ÿ��, ���� };
enum { ������, ������, �Ķ��� };
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
    if(m_color == ������) getFrame()->setPen(RGB(0, 0, 0), 1);
    else if(m_color == ������) getFrame()->setPen(RGB(255, 0, 0), 1);
    else if (m_color == �Ķ���) getFrame()->setPen(RGB(0, 0, 255), 1);
    
    if(m_type == �簢��) getFrame()->rectangle(start_x, start_y + m_MenuBar.getHeight(), end_x - start_x, end_y - start_y - m_MenuBar.getHeight());
    else if (m_type == Ÿ��) getFrame()->ellipse(start_x, start_y + m_MenuBar.getHeight(), end_x - start_x, end_y - start_y - m_MenuBar.getHeight());
    else if (m_type == ����) getFrame()->line(start_x, start_y + m_MenuBar.getHeight(), end_x - start_x, end_y - start_y - m_MenuBar.getHeight());
  
    
}

Point::~Point()
{
}
