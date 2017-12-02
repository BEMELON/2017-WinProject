#pragma once
#include "Window.h"
#include "MenuBar.h"

class Point :
    public Window
{
public:
    Point(int x, int y,int type, int color);
    ~Point();
    void setEnd(int x, int y);
    //int start_x, start_y;
    //int end_x, end_y;
    int m_type = 0,m_color = 0;
    void display();
    bool isInside(int x, int y);
    void MovePos(int x, int y);

    //�巡�װ� �Ǵ� ������ üũ�� ���ִ� �Լ�
    bool isMoving = false;
    //�ϼ� �Ǿ����� üũ�� ���ִ� ����
    bool isCompleted;
    MenuBar m_MenuBar;
};

