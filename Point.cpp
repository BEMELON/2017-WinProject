#include "stdafx.h"
#include "Point.h"
#include "Frame.h"
#include "MenuBar.h"

enum { �簢��, Ÿ��, ���� };
enum { ������, ������, �Ķ��� };
Point::Point(int x, int y, int type, int color)
    :m_type(type), m_color(color), isCompleted(false)
{   
    m_x = x; m_y = y;
}

void Point::setEnd(int x, int y)
{
    m_xsize = x - m_x ; m_ysize = y - m_y;
}

bool Point::isInside(int x, int y)
{
    if (m_xsize < 0 && m_ysize < 0) {
        return x <= m_x && x > m_x + m_xsize && y <= m_y && y > m_y + m_ysize;
    }
    else if (m_xsize < 0 && m_ysize > 0) {
        return x <= m_x&&x > m_x + m_xsize && y >= m_y && y < m_y + m_ysize;
    }
    else if (m_xsize > 0 && m_ysize < 0) {
        return x >= m_x && x < m_x + m_xsize && y <= m_y && y >m_y + m_ysize;
    }
    else return x >= m_x&&x < m_x + m_xsize && y >= m_y && y < m_y + m_ysize;
}
void Point::display()
{
    if(m_color == ������) getFrame()->setPen(RGB(0, 0, 0), 1);
    else if(m_color == ������) getFrame()->setPen(RGB(255, 0, 0), 1);
    else if (m_color == �Ķ���) getFrame()->setPen(RGB(0, 0, 255), 1);
    
    if (m_type == �簢��) getFrame()->rectangle(m_x, m_y, m_xsize, m_ysize);
    else if (m_type == Ÿ��) getFrame()->ellipse(m_x, m_y, m_xsize, m_ysize);
    else if (m_type == ����) getFrame()->line(m_x, m_y, m_xsize, m_ysize);
  
    
}



Point::~Point()
{
}
