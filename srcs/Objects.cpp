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


Triangle::Triangle()
{
    x_start = 800.0f;
    y_start = 500.0f;
    x = 160.0f;
    y = 160.0f;
    type = "Triangle";
    width = 120.0f; //change later
    height = 80.0f; //change later
    r = 1.0f;
    g = 0.0f;
    b = 0.0f;
    center = false;
}

void Triangle::draw() {
    float halfBase = 60.0f;
    float topY = y + 40.0f;
    float bottomY = y - 60.0f;
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES);
        glVertex2f(x, topY);
        glVertex2f(x - halfBase, bottomY);
        glVertex2f(x + halfBase, bottomY);
    glEnd();
}

void Triangle::startDrag(int mx, int my){
    dragged = true;
    xoffset = x - mx;
    yoffset = y - my;
}

void Triangle::stopDrag(){
    dragged = false;
}

void Triangle::dragTo(int mx, int my){
    if (dragged){
        x = mx + xoffset;
        y = my + yoffset;
    }
}

bool Triangle::isClicked(int mx, int my) {
    float halfBase = 60.0f;          
    float topY = y + 40.0f;      
    float bottomY = y;    

    float leftX = x - halfBase;
    float rightX = x + halfBase;

    return mx >= leftX && mx <= rightX && my >= bottomY && my <= topY;
}

void Triangle::put_in_middle()
{
    x = x_start;
    y = y_start;
    dragged = false;
    center = true;
}
