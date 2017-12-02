#include "stdafx.h"
#include "Container.h"
#include "Frame.h"
#include <string>
#include <list>
using namespace std;
Container::Container()
	:Window(0,0,0,0)
{
}
Container::Container(std::string name)
    : Window(name, 0, 0, 0, 0)
{
}

Container::~Container()
{
	// *** 모든 윈도을 delete합니다.
    m_windowList.clear();
 
}

void Container::onMouseClick(int x, int y)
{
    for (list<Window *>::reverse_iterator iter = m_windowList.rbegin(); iter != m_windowList.rend(); ++iter) {
        (*iter)->onMouseClick(x, y);
    }
   
}

void Container::addWindowFirst(Window * w)
{
    m_windowList.push_front(w);
    w->setContainer(this);
  
}
void Container::addWindowLast(Window * w)
{
    m_windowList.push_back(w);
    w->setContainer(this);
}


Window * Container::find(int x, int y)
{

    for (list<Window *>::reverse_iterator iter = m_windowList.rbegin();iter != m_windowList.rend(); ++iter) {
        if ((*iter)->isInside(x, y)) return (*iter);
    }

    for (list<Window *>::iterator iter = m_windowList.begin(); iter != m_windowList.end(); ++iter) {
        (*iter)->setStat();
    }
    return nullptr;
}


Container::Container(int x, int y, int sx, int sy)
	:Window(x, y, sx, sy)
{
}


void Container::display()
{
	Window::display();
    for (list<Window *>::iterator iter = m_windowList.begin(); iter != m_windowList.end(); ++iter) {
        (*iter)->display();
    }
}
