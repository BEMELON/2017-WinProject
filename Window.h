#pragma once
#include <string>
//void print(string);
void print(int);
using namespace std;
class Frame;
class Container;
class Window {
public:
	Window(int x, int y, int sx, int sy);
	Window(string s, int x, int y, int sx, int sy);
	//void setFrame(Frame *);
	void setContainer(Container * con);
	virtual void display();
	virtual void drawContent();
	virtual void onMouseClick(int x, int y);
	virtual Window * find(int x, int y);
	virtual bool isInside(int x, int y);
	string getTitle();
	void setX(int x);
	void setSize(int, int);
	Frame * getFrame();
protected:
	int m_x, m_y, m_xsize, m_ysize;
	string m_text;
	//Frame *m_frame;  getFrame() 함수로 대체
	Container *m_container;
private:
public:
	Window();
	
	virtual void setStat() { /* empty*/}
	void setTitle(string s);
	virtual void drawBorder();
    virtual void setPos(int x, int y);
    virtual void setPos(int x, int y, int m_xsize, int m_ysize, int m_cnt) { /*empty */}
};
