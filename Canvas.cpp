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
}


//void Canvas::setFrame(Frame *f)
//{
//	m_frame = f;
//}


void Canvas::onMouseDown(int x, int y)
{
	string s = "Canvas: " + to_string(x) + ", " + to_string(y) + "\n";
	OutputDebugString(s.c_str());

    m_list.push_back(new Point(x, y, getFrame()->m_FigureType, getFrame()->m_FigureColor));
    m_list.back()->setContainer(m_container);


    //m_Point[PointCnt] = new Point(x, y,getFrame()->m_FigureType,getFrame()->m_FigureColor);
    //m_Point[PointCnt]->setContainer(m_container);

   
}

void Canvas::onMouseUp(int x, int y)
{
    /*
    if (m_Point[PointCnt] != 0) {
        m_Point[PointCnt++]->setEnd(x, y);
    }*/

    if (!m_list.empty() && !m_list.back()->isCompleted) {
        m_list.back()->setEnd(x, y); m_list.back()->isCompleted = 1;
    }

    getFrame()->invalidate();
}


void Canvas::display()
{
	//getFrame()->drawText("여기는 캔버스", 200,200);
    for (list<Point *>::iterator iter = m_list.begin(); iter != m_list.end() ; iter++) {
        if((*iter)->isCompleted) (*iter)->display();
    }
    
    /*
     list<Point ::iterator iterEnd = m_list.end();
  for(list<Point>::iterator iterPos = m_list.begin(); 
    iterPos != iterEnd; 
    ++iterPos )
  {
      iterPos->display();
    //getFrame()->invalidate();
    */
}
