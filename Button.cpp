#include "stdafx.h"
#include "Button.h"
#include "Frame.h"

Button::Button()
{
}


Button::~Button()
{
}


Button::Button(int x, int y, int sx, int sy)
	:Window(x, y, sx, sy)
{
}

Button::Button(string s, int x, int y, int sx, int sy)
	: Window(s, x, y, sx, sy)
{
}

void Button::drawContent()
{
	string temp = m_text + to_string(m_count);
	getFrame()->drawText(temp, m_x + 5, m_y + 5);
}


void Button::onMouseClick(int x, int y)
{
	m_count++;
	display();
}
