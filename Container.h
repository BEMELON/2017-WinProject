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
    Window * windows[100];  // ���߿��� ����� �� ����Ʈ�� �ٲ���Ѵ�.
    MenuBar * m_Menubar;
    int numWidget = 0;
};
