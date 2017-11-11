#pragma once
#include "Window.h"
#include <iostream>
class Canvas :
    public Window
{
public:
    Canvas(std::string name,int x, int y, int sx, int sy);
    void display();
    ~Canvas();
};

