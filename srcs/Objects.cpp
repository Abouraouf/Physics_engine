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
    y_start = 900.0f;
    x = 160.0f;
    y = 160.0f;
    type = "Triangle";
    r = 1.0f;
    g = 0.0f;
    b = 0.0f;
    center = false;
    velocity_y = 0.0f;
    gravity = 1800.0f;
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

void Triangle::dragTo(int mx, int my)
{
    if (!dragged)
        return;

    float newX = mx + xoffset;
    float newY = my + yoffset;

    float topLimit = WINDOW_HEIGHT - 40.0f;
    float bottomLimit = (WINDOW_HEIGHT * 0.33f) + 60.0f;

    if (newY > topLimit)
        y = topLimit;
    else if (newY < bottomLimit)
        y = bottomLimit;
    else
        y = newY;

    if (newX < 60.0f)
        x = 60.0f;
    else if (newX > 1540.0f)
        x = 1540.0f;
    else
        x = newX;
}


bool Triangle::isClicked(int mx, int my) {
    float halfBase = 60.0f;          
    float topY = y + 40.0f;      
    float bottomY = y - 60.0f;    

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

void Triangle::update(float dt) {
    if (!dragged && center) {
        apply_gravity(dt);
        std::cout << "asd" << std::endl;
    }
}

void Triangle::apply_gravity(float dt)
{
    float bottomLimit = (WINDOW_HEIGHT * 0.33f) + 60.0f;
    if (!dragged && center) {     // only apply gravity if not being dragged or centered
        velocity_y += gravity * dt;    // update velocity_y
        y -= velocity_y * dt;        // update position (y decreases as it falls)
        // prevent falling below the bottom of the window
        if (y  < bottomLimit) {
            y = bottomLimit;
            velocity_y = 0.0f;         // stop at the floor
        }
    }
}
