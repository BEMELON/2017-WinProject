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
    Menu *menuFile, *menuEdit;
    MenuItem *miOpen, *miSave, *miExit, *miCopy, *miCut, *miPaste;
    
};

