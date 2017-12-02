#pragma once
#include "Window.h"
#include <string>
#include <list>
using namespace std;
class Container :
	public Window
{
public:
	Container();
    Container(std::string name);
	virtual ~Container();	// 가상 소멸자.
protected:
    list<Window *> m_windowList;
    void onMouseClick(int x, int y);
public:
	void addWindowLast(Window * w);
	void addWindowFirst(Window * w);
	virtual Window * find(int x, int y);
	Container(int x, int y, int sx, int sy);
	virtual void display();
};

