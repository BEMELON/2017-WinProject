#include "stdafx.h"
#include "ForDebug.h"
#include <iostream>
//Window(string s, int x, int y, int sx, int sy);
ForDebug::ForDebug(std::string s, int x, int y, int sx, int sy)
    :Window(s, x, y, sx, sy) {}

void ForDebug::onMouseClick(int x, int y) {
    OutputDebugStringA(" ¹öÆ° \n");
}
ForDebug::~ForDebug()
{
}
