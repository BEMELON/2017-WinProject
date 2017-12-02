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
    //�� �̺�Ʈ��, �ϼ��� �Ǳ����� ȣ�� �Ǿ�ߵǰ�, �ϼ��� �� ���Ŀ� ȣ��Ǿ�� �ȵȴ�.
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
    //�ϼ��� �Ǿ��� ��쿡�� display �� ���־���Ѵ�.
    for (list<Point *>::iterator iter = m_list.begin(); iter != m_list.end() ; iter++) {
        if((*iter)->isCompleted) (*iter)->display();
    }   
}
