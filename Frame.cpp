#include "stdafx.h"
#include "Frame.h"
#include "stdio.h"
#include "iostream"
#include "string"
#include "Window.h"
#include "Button.h"
#include "MenuItem.h"
using namespace std;
enum{�簢��,Ÿ��,����};
enum{������,������,�Ķ���};
Frame::Frame(HWND w):Container(0,0,640,480),myWnd(w)
{
	hDC = ::GetDC(w);
	//setFrame(this);  // �̳� �ʿ��ϴ�.
	setContainer(this);   // �ڽ��� ����Ű�� ���� Frame���� ǥ��.
	//onInitialize();
}

void Frame::setWnd(HWND hWnd) {

}

Frame::~Frame()
{
	 // *** ��� ������ delete�մϴ�.
	/*
	for (int i = 0; i < numWindows; i++) {
		delete m_window[i];
	}
	numWindows = 0;
	*/
}

void Frame::OnLButtonDown(long wParam, int x, int y)
{
	// Frame�� Ư���� Container�̹Ƿ� Override�Ѵ�.
	// OutputDebugString("Frame::Click\n");

	if (!m_menubar) return;  // �׷� ���� ������ menubar�� ���ٸ�...
	if (m_menubar->isInside(x, y)) {
		m_menubar->onMouseClick(x, y);
		return ;
	}
	m_canvas->onMouseDown(x, y - m_menubar->getHeight());
 
	/* 
	control key�� shift key� ���� �ٸ��� �Ϸ���
	if (wParam & MK_CONTROL)  .. MK_SHIFT ��

	*/
	// �� �ڵ�� �׽�Ʈ���̰�, view ��ü�� OnLButtonDown �Լ��� ȣ����
}

void Frame::OnLButtonUp(long wParam, int x, int y)
{
    m_canvas->onMouseUp(x, y);
	/*
	 * �Ʒ��� �� ����, ä�� ������ �����ϴ� ����� �˷��ݴϴ�.
	setPenColor(RGB(255, 0, 0));
	setFillColor(RGB(255, 255, 0));
	rectangle(x, y, 100, 200);
	*/
}

void Frame::OnRButtonDown(long wParam, int x, int y)
{
	// ���α׷� ���� ����� �����ϱ� ���� ���� ��ư Ŭ���� �Ʒ� ���� ȣ���ϰ� ��������ϴ�.
	PostMessage(myWnd, WM_CLOSE, NULL, NULL);
}

void Frame::OnRButtonUp(long wParam, int x, int y)
{
	// 
}

void Frame::OnChar(long ch)
{
	// Ű���� �Է��� �Ǹ� �� �Լ��� �ڵ� ȣ��˴ϴ�.  cin�̳� getchar, scanf ����
	// ǥ�� �Է��Լ��� �۵����� ������ onchar �� �� �̿��ؾ� �մϴ�.
	/*
	string s;
	s = "�Էµ� ����: ";
	s += ch;
	setTextColor(RGB(200, 100, 100));
	drawText(s, 100, 100);
	*/
	OutputDebugString("Key �Է�.\n");

}


void Frame::setPenColor(COLORREF color)
{
	thePen = CreatePen(PS_SOLID, 1, color);
	SelectObject(hDC, thePen);
}

void Frame::setPen(COLORREF color, int width)
{
	thePen = CreatePen(PS_SOLID, width, color);
	SelectObject(hDC, thePen);
}

void Frame::setFillColor(COLORREF color)
{
	theBrush = CreateSolidBrush(color);
	SelectObject(hDC, theBrush);
}


void Frame::setTextColor(COLORREF color)
{
	SetTextColor(hDC, color);
}

void Frame::processEvent(Window * src)
{
        if (src->getTitle() == "�簢��") m_FigureType = �簢��;
        else if (src->getTitle() == "Ÿ��") m_FigureType = Ÿ��;
        else if (src->getTitle() == "����") m_FigureType = ����;

        if (src->getTitle() == "������") m_FigureColor = ������;
        else if (src->getTitle() == "������") m_FigureColor = ������;
        else if (src->getTitle() == "�Ķ���")m_FigureColor = �Ķ���;
}


void Frame::rectangle(int x, int y, int sizeX, int sizeY)
{
	Rectangle(hDC, x, y, x + sizeX, y + sizeY);
}

void Frame::ellipse(int x, int y, int sizeX, int sizeY)
{
	Ellipse(hDC, x, y, x + sizeX, y + sizeY);
}

void Frame::line(int x, int y, int sizeX, int sizeY)
{
	MoveToEx(hDC, x, y, NULL);
	LineTo(hDC, x + sizeX, y + sizeY);
}


void Frame::drawText(std::string str, int x, int y)
{
	TextOut(hDC, x, y, str.c_str(), strlen(str.c_str()));
}

// ȭ���� ���� ����� �ȵǾ� �ִٰ� �˸��� �Լ��Դϴ�.
// �� �Լ��� ȣ���ϸ� ȭ���� �������� 
// Main �ʿ� case WM_PAINT: �κ��� ����˴ϴ�.
// �ᱹ�� View ��ü�� display�� ����ǰ���.
void Frame::invalidate()
{
	InvalidateRect(myWnd, NULL, true);
}

// ��� �������� onInitialize �Լ����� �ʱ�ȭ����.
void Frame::onInitialize()
{
    //empty	
}


/*
void Frame::registerWindow(Window * w)
{
	 // *** ������ �迭�� �����ְ�, �������� �� View ��ü�� �����͸� ����������.
	windows[numWindows++] = w;
	w->setFrame(this);
}
*/

/*
Window * Frame::find(int x, int y) {
	 // �� �������� isInside(x, y) �� ��� Ŭ���� ��ü�� �����͸� ��������.
	 bool b = m_menubar->isInside(x, y);
	 if (b) {
		 m_menubar->onMouseClick(x, y);
		 return 0;
	 } 
	 else OutputDebugString("Click ");
	 //for (int i = 0; i < this->numWidget; i++) {
	 //if (windows[i]->isInside(x, y))
	 //return windows[i];
	 //}
	 return (Window *)NULL;
}
*/

void Frame::addMenuBar(MenuBar * mb)
{
	if (!mb) return;
	addWindowLast(mb);
	//mb->setFrame(this);
	mb->setContainer(this);
	mb->setSize(600, 30);
	m_menubar = mb;
}


void Frame::setSize(int x, int y)
{
	Window::setSize(x, y);
	if (m_menubar) m_menubar->setSize(x, 30);
}


void Frame::addCanvas(Canvas * c)
{
	if (!c) return;
	addWindowLast(c);
	//c->setFrame(this);
	c->setContainer(this);
	m_canvas = c;
}
