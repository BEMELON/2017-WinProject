#pragma once
#include "Window.h"
#include <string>
class MenuBar;
class Container :
    public Window
{
public:
    Container(std::string name,int x,int y,int sx, int sy);
    Container(int x, int y, int sx, int sy);
    Container();
    ~Container();
protected:
    Window * windows[100];  // 나중에는 제대로 된 리스트로 바꿔야한다.
    MenuBar * m_Menubar;
    int numWidget = 0;
};
