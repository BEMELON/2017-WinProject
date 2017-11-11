#include "stdafx.h"
#include "Canvas.h"
#include "Frame.h"
#include <string>

Canvas::Canvas(std::string name, int x, int y, int sx, int sy)
    :Window(name, x, y, sx, sy)
{
}

void Canvas::display()
{
    m_Frame->setPen(RGB(100, 100, 100), 1);
    m_Frame->rectangle(m_x, m_y, m_xsize, m_ysize);  
}

Canvas::~Canvas()
{
}
