#pragma once
#include "Window.h"
#include <string>
class Menu;
class Frame;
class MenuBar
    :public Window
{
public:
    MenuBar(std::string name,int x, int y, int sx, int sy);
    MenuBar(int x, int y, int sx, int sy);
    void setFrame(Frame *);
    void onMouseClick(int x, int y);
    void display();
    void setMenu(Menu *);
    ~MenuBar();
private:
    Menu *m_Menu[10];

protected:
    int m_MenuCnt;
};

