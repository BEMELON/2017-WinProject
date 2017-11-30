#pragma once
#include "Window.h"
#include <string>
class Container :
	public Window
{
public:
	Container();
    Container(std::string name);
	virtual ~Container();	// ���� �Ҹ���.
protected:
	Window * m_window[100];  // ���߿��� ����� �� ����Ʈ�� �ٲ���Ѵ�.
    void onMouseClick(int x, int y);

	int numWindows = 0;
public:
	void addWindowLast(Window * w);
	void addWindowFirst(Window * w);
	virtual Window * find(int x, int y);
	Container(int x, int y, int sx, int sy);
	virtual void display();
};

