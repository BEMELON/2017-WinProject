#include "stdafx.h"
#include "Menu.h"
#include "Frame.h"
#include "MenuItem.h"
#include "Window.h"
void print(string);
Menu::Menu(string title):Container(0,0,100,30)
{
	m_text = title;
}

void Menu::addMenuItem(Window * w)
{
    w->setContainer(getFrame());
    w->setPos(m_x, m_y, m_xsize, m_ysize, numWindows);
    m_window[numWindows++] = w;
}


Window* Menu::find(int x, int y)
{
    if (isInside(x, y)) {
        m_stat = true; getFrame()->invalidate();
        return this;
    }
    else if (m_stat) return Container::find(x, y);
    else {
        //m_stat = false;  getFrame()->invalidate();
        return (Window *)0;
    }
}

void Menu::display()
{
    Window::display();
    if (m_stat)
    {
        for (int i = 0; i < numWindows; i++)
        {
            m_window[i]->display();
        }
    }
    else return;
}


void Menu::setStat()
{
    if (m_stat)
    {
        m_stat = false;
        getFrame()->invalidate();
    }
    return;
}

bool Menu::isInside(int x, int y) 
{
    if (Window::isInside(x, y)) return true;
    for (int i = numWindows - 1; i >= 0; i--)
    {
        if (m_window[i]->isInside(x, y) && m_stat) return true;
    }
    return false;
}
Menu::~Menu()
{
}



void Menu::onMouseClick(int x, int y)
{
    if (m_stat == false) {
        m_stat = true; getFrame()->invalidate();
    }
    else {
        for (int i = numWindows - 1; i >= 0; i--) {
            if (m_window[i]->isInside(x, y))
                m_window[i]->onMouseClick(x, y);
        }
    }
}

