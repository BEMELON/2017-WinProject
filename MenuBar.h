#pragma once
#include "Window.h"
#include "Menu.h"
class MenuBar :
	public Container
{
public:
	MenuBar();
	~MenuBar();
	void onMouseClick(int x, int y);
	void addMenu(Menu *);
	int getHeight();
	bool isInside(int x, int y);
    
};

