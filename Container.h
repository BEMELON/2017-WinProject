#pragma once
#include "Window.h"
#include <string>
class Container :
	public Window
{
public:
	Container();
    Container(std::string name);
	virtual ~Container();	// 가상 소멸자.
protected:
	Window * m_window[100];  // 나중에는 제대로 된 리스트로 바꿔야한다.
    void onMouseClick(int x, int y);

	int numWindows = 0;
public:
	void addWindowLast(Window * w);
	void addWindowFirst(Window * w);
	virtual Window * find(int x, int y);
	Container(int x, int y, int sx, int sy);
	virtual void display();
};

