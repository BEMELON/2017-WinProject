#pragma once
#include "Window.h"
#include <string>
class MenuItem :
    public Window
{
public:
    MenuItem(std::string name);
    ~MenuItem();
    void setPos(int x, int y, int sx, int sy,int cnt);
};

