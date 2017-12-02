#include "stdafx.h"
#include "MenuBar.h"


MenuBar::MenuBar()
{
	m_x = 0; m_y = 0;
	m_text = "Menubar";
	m_xsize = 640;
	m_ysize = 30;
}


MenuBar::~MenuBar()
{
}

void MenuBar::onMouseClick(int x, int y)
{
	//OutputDebugString("MenuBar Clicked. ");
	//Container::onMouseClick(x, y);  // �Ҽ� ���� �߿� �ش��ڸ� �ҷ��ִ� ��. ���߿� �ٲ۴�.
	Menu *m = (Menu *)find(x, y);
    for (list<Window *>::iterator iter = m_windowList.begin(); iter != m_windowList.end(); ++iter) {
        if (!(*iter)->isInside(x, y)) (*iter)->setStat();
        else (*iter)->onMouseClick(x, y);
    }
    Window::onMouseClick(x, y);
}

void MenuBar::addMenu(Menu *m) {
	
    m_windowList.push_back(m);
	m->setContainer(this);
    int i = 0;
    for (list<Window *>::iterator iter = m_windowList.begin(); iter != m_windowList.end(); ++iter,i++) {
        (*iter)->setX(i * 100);
    }
}

int MenuBar::getHeight()
{
	return m_ysize;
}

bool MenuBar::isInside(int x, int y)
{
	if (Window::isInside(x, y)) return true;     // �޴��� ��ü �κ��̰ų�
	if (find(x, y)) return true;
		  // �ƴϴ��� ������ �޴� �κ��� �� �ִ�.
	return false;
}


