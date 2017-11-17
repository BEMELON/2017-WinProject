#include "stdafx.h"
#include <string>
#include "MenuBar.h"
#include "Frame.h"
#include "Menu.h"
MenuBar::MenuBar(std::string name,int x, int y, int sx, int sy)
    :Container(name,x, y, sx, sy)
{    
}

MenuBar::MenuBar(int x, int y, int sx, int sy)
    :Container(x, y, sx, sy)
{
}

void MenuBar::display() 
{
    m_Frame->rectangle(0, 0, m_xsize, m_ysize);
    for (int i = 0; i < m_MenuCnt; i++) 
    {
        m_Menu[i]->draw();
    }
}

void MenuBar::setFrame(Frame *f)
{
    m_Frame = f;
    f->setMenuBar(this);
}

void MenuBar::onMouseClick(int x, int y)
{
    OutputDebugString(m_text.c_str());
    OutputDebugString(" Clicked \n");
    for (int i = 0; i < m_MenuCnt; i++)
    {
        bool check;
        check = m_Menu[i]->isInside(x,y);
        if (check)
            m_Menu[i]->onMouseClick(x, y);
    }
}

void MenuBar::setMenu(Menu *m)
{   
    if (m_MenuCnt < 10)
    {
        m_Menu[m_MenuCnt] = m;
        m_Menu[m_MenuCnt]->setPos(m_MenuCnt);
        m_Menu[m_MenuCnt]->setFrame(m_Frame);
        m_MenuCnt++;
    }
}

MenuBar::~MenuBar()
{
}
