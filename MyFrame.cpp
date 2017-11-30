#include "stdafx.h"
#include "MyFrame.h"
#include "MenuItem.h"

MyFrame::MyFrame(HWND hwnd)
    :Frame(hwnd)
{

}

void MyFrame::onInitialize()
{
    // *** 모든 윈도들을 여기에서 초기화하자.
    addCanvas(new Canvas());
    addMenuBar(new MenuBar());

    // menuFile 등등은 멤버 변수로 했다. 나중에  event source를 파악해야하니까.
    m_menubar->addMenu(menuFigure = new Menu("도형"));
    m_menubar->addMenu(menuColor = new Menu("색"));

    menuFigure->addMenuItem(miSquare = new MenuItem("사각형"));
    menuFigure->addMenuItem(miElipse = new MenuItem("타원"));
    menuFigure->addMenuItem(miLine = new MenuItem("선분"));

    menuColor->addMenuItem(miBlack = new MenuItem("검은색"));
    menuColor->addMenuItem(miRed = new MenuItem("빨간색"));
    menuColor->addMenuItem(miBlue = new MenuItem("파란색"));
}

MyFrame::~MyFrame()
{
}
