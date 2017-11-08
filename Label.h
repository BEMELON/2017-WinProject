#pragma once
#include "Window.h"
#include <string>
class Label :public Window {
public:
    Label(std::string s, int x, int y, int sx, int sy);
    void onMouseClick(int x, int y);
    ~Label();
};