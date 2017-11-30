#include "stdafx.h"
#include "Window.h"
#include "Frame.h"
#include <fstream>

Window::Window(int x, int y, int sx, int sy) :
	m_x(x), m_y(y), m_xsize(sx), m_ysize(sy), m_text("") {
}
Window::Window(string s, int x, int y, int sx, int sy)
	: Window(x, y, sx, sy)
{
	m_text = s;
}
//void Window::setFrame(Frame *v) {
//	m_frame = v;
//}
void Window::setContainer(Container * con)
{
	m_container = con;
}
void Window::display() {
	//OutputDebugString("Window"); 
	//OutputDebugString(m_text.c_str());
	//std::string s = "pos:";
	//s += to_string(m_x) + "," + to_string(m_y) + "," + to_string(m_xsize) + "," + to_string(m_ysize) + "\n";
	//OutputDebugString(s.c_str());
	drawBorder();
	drawContent();
}
void Window::drawContent() {
	getFrame()->drawText(m_text, m_x + 5, m_y + 5);
}
void Window::onMouseClick(int x, int y) {
	//logger << "Window clicked, ";
	//logger << "Name: " << m_text << endl;
	OutputDebugString(m_text.c_str());
	OutputDebugString(" Clicked \n");
}

bool Window::isInside(int x, int y) {
	//OutputDebugString("Testing inside: ¸¶¿ì½º:"); print(x); print(y);
	//OutputDebugString(m_text.c_str()); print(m_x); print(m_y); print(m_xsize); print(m_ysize);
	return m_x <= x && x < m_x + m_xsize &&
		m_y <= y && y < m_y + m_ysize;
}


Window::Window()
{
	m_x = m_y = 0;
	m_text = "";
}

string Window::getTitle() {
	return m_text;
}




Window * Window::find(int x, int y)
{
	if (isInside(x, y))
		return this;
	else
		return nullptr;
}


void Window::setTitle(string s)
{
	m_text = s;
}


void Window::drawBorder()
{
	getFrame()->setPen(RGB(100, 100, 100), 1);
	getFrame()->rectangle(m_x, m_y, m_xsize+1, m_ysize+1);
}

void Window::setX(int x) {
	m_x = x;
}

void Window::setSize(int sx, int sy)
{
	m_xsize = sx;
	m_ysize = sy;
}
Frame * Window::getFrame() {
	if (m_container == (Frame *)this) {
		return (Frame *)this;
	} else {
		return m_container->getFrame();
	}
}

void Window::setPos(int x, int y)
{
	m_x = x; m_y = y;
}
