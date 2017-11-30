#include "stdafx.h"
#include "MyFrame.h"
#include "MenuItem.h"

MyFrame::MyFrame(HWND hwnd)
    :Frame(hwnd)
{

}

void MyFrame::onInitialize()
{
    // *** ��� �������� ���⿡�� �ʱ�ȭ����.
    addCanvas(new Canvas());
    addMenuBar(new MenuBar());

    // menuFile ����� ��� ������ �ߴ�. ���߿�  event source�� �ľ��ؾ��ϴϱ�.
    m_menubar->addMenu(menuFigure = new Menu("����"));
    m_menubar->addMenu(menuColor = new Menu("��"));

    menuFigure->addMenuItem(miSquare = new MenuItem("�簢��"));
    menuFigure->addMenuItem(miElipse = new MenuItem("Ÿ��"));
    menuFigure->addMenuItem(miLine = new MenuItem("����"));

    menuColor->addMenuItem(miBlack = new MenuItem("������"));
    menuColor->addMenuItem(miRed = new MenuItem("������"));
    menuColor->addMenuItem(miBlue = new MenuItem("�Ķ���"));
}

MyFrame::~MyFrame()
{
}
