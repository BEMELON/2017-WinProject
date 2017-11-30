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
    addMenuBar(new MenuBar());
    addCanvas(new Canvas());

    // menuFile ����� ��� ������ �ߴ�. ���߿�  event source�� �ľ��ؾ��ϴϱ�.
    m_menubar->addMenu(menuFile = new Menu("����"));
    m_menubar->addMenu(menuEdit = new Menu("����"));

    menuFile->addMenuItem(miOpen = new MenuItem("����"));
    menuFile->addMenuItem(miSave = new MenuItem("����"));
    menuFile->addMenuItem(miExit = new MenuItem("������"));

    menuEdit->addMenuItem(miCopy = new MenuItem("����"));
    menuEdit->addMenuItem(miCut = new MenuItem("�ڸ���"));
    menuEdit->addMenuItem(miPaste = new MenuItem("���̱�"));
}

MyFrame::~MyFrame()
{
}
