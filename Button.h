#pragma once
#include "Window.h"
class Button :
	public Window
{
public:
	Button();
	~Button();
	Button(int x, int y, int sx, int sy);
	Button(string s, int x, int y, int sx, int sy);

protected:
	int m_count = 0;
public:
	void drawContent();
	void onMouseClick(int x, int y);
};

