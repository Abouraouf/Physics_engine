#pragma once
#include <iostream>

#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 1000

class Window {
private:
    std::string name;
public:
    const std::string& get_name();
    Window();
    ~Window();
};