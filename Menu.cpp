#include "stdafx.h"
#include "Menu.h"
#include "Frame.h"
#include "Window.h"
#include <string>

Menu::Menu(const std::string name, int x, int y, int sx, int sy)
    :MenuBar(name, x, y, sx, sy)
{
    //사이즈 임시로 설정
}

void Menu::setFrame(Frame *f)
{
    m_Frame = f;
}
void Menu::setPos(int MenuCnt)
{
    if (MenuCnt == 0) m_x = 0;
    else m_x = (m_xsize / 10) * MenuCnt;
    m_xsize = m_xsize / 10;
}


void Menu::draw()
{
    m_Frame->rectangle(m_x, m_y, m_xsize, m_ysize);
    m_Frame->drawText(m_text, m_x+15, m_y+5);
}

Menu::~Menu()
{
}
