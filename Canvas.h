#pragma once
#include "Window.h"
#include <iostream>
class Canvas :
    public Window
{
public:
    Canvas(std::string name,int x, int y, int sx, int sy);
    void onMouseClick(int x, int y);
    void display();
    ~Canvas();
};

