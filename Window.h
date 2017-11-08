#pragma once
#include <string>
using namespace std;
class View;
class Window {
public:
	Window(int x, int y, int sx, int sy);
	Window(string s, int x, int y, int sx, int sy);
	void setView(View *);
	void display();
	void drawContent();
	virtual void onMouseClick(int x, int y);
	bool isInside(int x, int y);
protected:
	int m_x, m_y, m_xsize, m_ysize;
	string m_text;
	View *m_view;
private:
};
