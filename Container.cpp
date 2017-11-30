#include "stdafx.h"
#include "Container.h"
#include <string>
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
	for (int i = 0; i < numWindows; i++) {
		delete m_window[i];
	}
	numWindows = 0;
}

void Container::onMouseClick(int x, int y)
{
    for (int i = numWindows - 1; i >= 0; i--) {
        m_window[i]->onMouseClick(x, y);
    }
}

void Container::addWindowFirst(Window * w)
{
	for (int i = numWindows; i > 0; i--) {
		m_window[i] = m_window[i - 1];
	}
	m_window[0] = w;
	w->setContainer(this);
	numWindows++;
}
void Container::addWindowLast(Window * w)
{
	m_window[numWindows++] = w;
	w->setContainer(this);
}


Window * Container::find(int x, int y)
{

	// 역방향으로 찾고 순방향으로 그린다.
	for (int i = numWindows - 1; i >= 0; i--) {
		//OutputDebugString(m_window[i]->getTitle().c_str());
		if (m_window[i]->isInside(x, y)) {
			return m_window[i];
		}
	}
    for (int i = 0; i < numWindows; i++) {
        m_window[i]->setStat();
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
	for (int i = 0; i < numWindows; i++) {
		m_window[i]->display();
		//OutputDebugString("Component ");
	}
}
