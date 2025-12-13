#include "../headers/Window.hpp"

Window::Window() : name("Physics engine") {}

const std::string& Window::get_name() { return name; }

Window::~Window() {}