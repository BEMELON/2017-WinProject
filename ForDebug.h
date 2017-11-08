#pragma once
#include "Window.h"
class ForDebug :
    public Window
{
public:
    ForDebug(string s, int x, int y, int sx, int sy);
    void onMouseClick(int x, int y);
    ~ForDebug();
};

