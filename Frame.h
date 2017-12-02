#pragma once
#include "iostream"
#include "Window.h"
#include "MenuBar.h"
#include "Canvas.h"
#include "Container.h"
class Frame: public Container
{
public:
	Frame(HWND);
	~Frame();
protected:
	HWND myWnd;
	HDC hDC;
	HBRUSH brushWhite, brushBlack;
	HPEN penWhite, penBlack;
	// �ӽ� ����
	int count = 0;
	HPEN thePen;
	HBRUSH theBrush;
public:
	virtual void setWnd(HWND hWnd);
	virtual void OnLButtonDown(long wParam, int x, int y);
	virtual void OnLButtonUp(long wParam, int x, int y);
	virtual void OnRButtonDown(long wParam, int x, int y);
	virtual void OnRButtonUp(long wParam, int x, int y);
	virtual void OnChar(long ch);
	void setPenColor(COLORREF color);         // �� ���� ����. �β��� 1�� �ڵ�.
	void setPen(COLORREF color, int width);   // �� ����� �β����� ����.
	void setFillColor(COLORREF color);
	void setTextColor(COLORREF color);
    void processEvent(Window * src);

	void rectangle(int x, int y, int sizeX, int sizeY);
	void ellipse(int x, int y, int sizeX, int sizeY);
	void line(int x, int y, int sizeX, int sizeY);
	void drawText(std::string str, int x, int y);
	void invalidate();
	virtual void onInitialize();
    void InitStatus();

protected:

public:
	MenuBar *m_menubar = nullptr;  
	Canvas *m_canvas = nullptr;
	void addMenuBar(MenuBar * mb);
	void setSize(int x, int y);
	void addCanvas(Canvas * c);
    int m_FigureType = 0;
    int m_FigureColor = 0;
    bool isChanged = false;
};

