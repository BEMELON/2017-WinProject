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
    addMenuBar(new MenuBar());
    addCanvas(new Canvas());

    // menuFile 등등은 멤버 변수로 했다. 나중에  event source를 파악해야하니까.
    m_menubar->addMenu(menuFile = new Menu("파일"));
    m_menubar->addMenu(menuEdit = new Menu("편집"));

    menuFile->addMenuItem(miOpen = new MenuItem("열기"));
    menuFile->addMenuItem(miSave = new MenuItem("저장"));
    menuFile->addMenuItem(miExit = new MenuItem("끝내기"));

    menuEdit->addMenuItem(miCopy = new MenuItem("복사"));
    menuEdit->addMenuItem(miCut = new MenuItem("자르기"));
    menuEdit->addMenuItem(miPaste = new MenuItem("붙이기"));
}

MyFrame::~MyFrame()
{
}
