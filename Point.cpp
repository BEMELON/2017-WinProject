#include "stdafx.h"
#include "Point.h"
#include "Frame.h"
#include "MenuBar.h"

enum { 사각형, 타원, 선분 };
enum { 검은색, 빨간색, 파란색 };
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
    if(m_color == 검은색) getFrame()->setPen(RGB(0, 0, 0), 1);
    else if(m_color == 빨간색) getFrame()->setPen(RGB(255, 0, 0), 1);
    else if (m_color == 파란색) getFrame()->setPen(RGB(0, 0, 255), 1);
    
    if (m_type == 사각형) getFrame()->rectangle(m_x, m_y, m_xsize, m_ysize);
    else if (m_type == 타원) getFrame()->ellipse(m_x, m_y, m_xsize, m_ysize);
    else if (m_type == 선분) getFrame()->line(m_x, m_y, m_xsize, m_ysize);
  
    
}



Point::~Point()
{
}
