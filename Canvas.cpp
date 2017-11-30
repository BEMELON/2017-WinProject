#include "stdafx.h"
#include "Canvas.h"
#include "Frame.h"
#include "Point.h"
Canvas::Canvas()
{
}


Canvas::~Canvas()
{
}


//void Canvas::setFrame(Frame *f)
//{
//	m_frame = f;
//}


void Canvas::onMouseDown(int x, int y)
{
	string s = "Canvas: " + to_string(x) + ", " + to_string(y) + "\n";
	OutputDebugString(s.c_str());
    m_Point[PointCnt] = new Point(x, y);
    m_Point[PointCnt]->setContainer(m_container);

    /*
    m_Point[PointCnt]->end_x = x + 80;
    m_Point[PointCnt++]->end_y = y + 80;
    getFrame()->invalidate();
    */
}

void Canvas::onMouseUp(int x, int y)
{
    //HDC hdc;
    //LineTo(hdc, start_x, start_y);
    if (m_Point[PointCnt] != 0) {
        m_Point[PointCnt]->end_x = x;
        m_Point[PointCnt]->end_y = y;
        PointCnt++;
    }

    getFrame()->invalidate();
}


void Canvas::display()
{
	//getFrame()->drawText("여기는 캔버스", 200,200);
    for (int i = 0; i < PointCnt; i++) {
        m_Point[i]->display();
    }
    //getFrame()->invalidate();
}
