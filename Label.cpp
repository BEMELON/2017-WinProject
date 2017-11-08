#include "stdafx.h"
#include "Label.h"
#include "Window.h"
#include <iostream>
//Window(string s, int x, int y, int sx, int sy);
Label::Label(std::string s, int x, int y, int sx, int sy)
    :Window(s, x, y, sx, sy) {}

void Label::onMouseClick(int x, int y) {
    OutputDebugStringA(" Label \n");
}
Label::~Label()
{
}
