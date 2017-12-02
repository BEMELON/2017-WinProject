#pragma once
#include "Window.h"
#include "Container.h"
class MenuItem;
class MenuBar;
class Canvas;
class Menu :
	public Container
{
public:
	Menu(string title);
	~Menu();
    void setStat();
	void onMouseClick(int x, int y);
    void addMenuItem(Window *);
    Window* find(int x, int y);
    bool m_stat = false;
    void display();
    bool isInside(int x, int y);
    
protected:

public:
	
};

