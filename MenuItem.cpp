#include "stdafx.h"
#include "MenuItem.h"
#include <string>

MenuItem::MenuItem(std::string m_name)
    :Window(m_name,0,0,0,0)
{
}
void MenuItem::setPos(int x,int y, int sx, int sy, int cnt)
{
    Window::setPos(x, y + (cnt+1) * sy);
    Window::setSize(sx, sy);
}

MenuItem::~MenuItem()
{
}
