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
	if (m) {
		m->onMouseClick(x, y);
	}
    else Window::onMouseClick(x, y);
}

void MenuBar::addMenu(Menu *m) {
	Container::addWindowLast(m);
	m->setContainer(this);
	for (int i = 0; i < numWindows; i++) {
		m_window[i]->setX(i * 100);
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


