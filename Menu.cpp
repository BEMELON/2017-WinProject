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
    w->setPos(m_x, m_y, m_xsize, m_ysize, m_windowList.size());
    m_windowList.push_back(w);
    
}


Window* Menu::find(int x, int y)
{
    if (isInside(x, y)) {
        m_stat = true; getFrame()->invalidate();
        return this;
    }
    else if (m_stat) {
        Window *temp = Container::find(x, y);
        getFrame()->processEvent(temp);
        return temp;
    }
    else {
        return (Window *)0;
    }
}

void Menu::display()
{
    Window::display();
    if (m_stat)
    {
        for (list<Window *>::iterator iter = m_windowList.begin(); iter != m_windowList.end(); ++iter) {
            (*iter)->display();
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
    for (list<Window *>::reverse_iterator iter = m_windowList.rbegin(); iter != m_windowList.rend(); ++iter) {
        if ((*iter)->isInside(x, y) && m_stat) return true;
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
        for (list<Window *>::reverse_iterator iter = m_windowList.rbegin(); iter != m_windowList.rend(); ++iter) {
            if ((*iter)->isInside(x, y)) {
                getFrame()->processEvent((*iter));
                getFrame()->isChanged = true;
                return (*iter)->onMouseClick(x, y);
            }
        }
    }
}

