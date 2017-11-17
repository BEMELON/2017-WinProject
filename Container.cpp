#include "stdafx.h"
#include "Container.h"
#include <string>

Container::Container(std::string name, int x, int y, int sx, int sy)
    :Window(name, x, y, sx, sy) {}

Container::Container(int x, int y, int sx, int sy)
    : Window(x, y, sx, sy) {}

Container::Container() : Window() {}

Container::~Container()
{
}
