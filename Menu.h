#pragma once
#include "MenuBar.h"
#include <string> 
class Menu :
    public MenuBar
{
public:
    Menu(const std::string name, int x, int y, int sx, int sy);
    void setPos(int Menucnt);
    void setFrame(Frame *);
    void draw();
    ~Menu();
private:
   
};

