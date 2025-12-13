#include "../headers/Objects.hpp"
#include "../headers/Window.hpp"
Objects::Objects()
    : x(0.0f), y(0.0f),
      width(1.0f), height(1.0f),
      r(0.5f), g(0.5f), b(0.5f),
      type("unknown"),
      state(0)
{}

Objects::~Objects(){}



void Triangle::draw() {
    float X = (WINDOW_WIDTH * 0.20f)  /  2;
    float Y = (WINDOW_HEIGHT * 0.33f)  /  2;

    float halfBase = 60.0f;
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(X, Y + 40.0f);
        glVertex2f(X - halfBase, Y / 2);
        glVertex2f(X + halfBase, Y / 2);
    glEnd();
}

void Square::draw() {
    // TODO: implement square drawing
}

void Circle::draw() {
    // TODO: implement circle drawing
}