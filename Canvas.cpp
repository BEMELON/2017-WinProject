#include "stdafx.h"
#include "Canvas.h"
#include "Frame.h"
#include "Point.h"
using namespace std;
Canvas::Canvas()
{
}


Canvas::~Canvas()
{
    m_list.clear();
}


void Canvas::onMouseDown(int x, int y)
{
	string s = "Canvas: " + to_string(x) + ", " + to_string(y) + "\n";
	OutputDebugString(s.c_str());

    m_list.push_back(new Point(x, y, getFrame()->m_FigureType, getFrame()->m_FigureColor));
    m_list.back()->setContainer(m_container);
}

void Canvas::onMouseUp(int x, int y)
{
    //이 이벤트는, 완성이 되기전에 호출 되어야되고, 완성이 된 이후에 호출되어서는 안된다.
    if (!m_list.empty() && !m_list.back()->isCompleted) {
        m_list.back()->setEnd(x, y); m_list.back()->isCompleted = true;
        getFrame()->invalidate();
    }

}

void Canvas::onKeyMouseClick(int x, int y)
{
    for (list<Point *>::reverse_iterator iter = m_list.rbegin(); iter != m_list.rend(); ++iter) {
        if ((*iter)->isCompleted) {
            if ((*iter)->isInside(x,y)) {
                m_list.erase((++iter).base());
                getFrame()->invalidate();
                break;
            }
        }
    }
}


void Canvas::display()
{
    //완성이 되었을 경우에만 display 를 해주어야한다.
    for (list<Point *>::iterator iter = m_list.begin(); iter != m_list.end() ; iter++) {
        if((*iter)->isCompleted) (*iter)->display();
    }   
}
