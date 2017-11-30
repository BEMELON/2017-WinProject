#pragma once
#include "Frame.h"
class MenuItem;
class Menu;
class MyFrame :
    public Frame
{
public:
    MyFrame(HWND);
    void onInitialize();
    ~MyFrame();
    Menu *menuColor, *menuFigure;
    MenuItem *miSquare, *miElipse, *miLine, *miRed, *miBlack, *miBlue;
    
};

