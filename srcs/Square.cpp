#include "../headers/Square.hpp"
#include "../headers/Window.hpp"

Square::Square(){
	x_start = 800.0f;
    y_start = 900.0f;
    x = 480.0f;
    y = 160.0f;
    type = "Square";
    r = 0.0f;
    g = 0.0f;
    b = 1.0f;
    center = false;
    velocity_y = 0.0f;
    gravity = 1800.0f;
}
void Square::draw() {
    float halfBase = 60.0f;
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
        glVertex2f(x - halfBase, y + halfBase);
        glVertex2f(x + halfBase, y + halfBase);
        glVertex2f(x + halfBase, y - halfBase);
        glVertex2f(x - halfBase, y - halfBase);
    glEnd();
}

void Square::startDrag(int mx, int my){
    dragged = true;
    xoffset = x - mx;
    yoffset = y - my;
}

void Square::stopDrag(){
    dragged = false;
}

void Square::dragTo(int mx, int my)
{
    if (!dragged)
        return;

    float newX = mx + xoffset;
    float newY = my + yoffset;

    float topLimit = WINDOW_HEIGHT - 60.0f;
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

bool Square::isClicked(int mx, int my) {
    float halfBase = 60.0f;          
    float topY = y + halfBase;      
    float bottomY = y - halfBase;    

    float leftX = x - halfBase;
    float rightX = x + halfBase;

    return mx >= leftX && mx <= rightX && my >= bottomY && my <= topY;
}

void Square::put_in_middle()
{
    x = x_start;
    y = y_start;
    dragged = false;
    center = true;
}

void Square::apply_gravity(float dt)
{
    float bottomLimit = (WINDOW_HEIGHT * 0.33f) + 60.0f;
    if (!dragged && center) {   
        velocity_y += gravity * dt;  
        y -= velocity_y * dt;     

        if (y  < bottomLimit) {
            y = bottomLimit;
            velocity_y = 0.0f;         
        }
    }
}
void Square::checkCollision(Objects* Other)
{
    Square* other = dynamic_cast<Square*>(Other);
    if (!other || other == this) return;

    float half = 60.0f;

    float thisLeft   = x - half;
    float thisRight  = x + half;
    float thisTop    = y + half;
    float thisBottom = y - half;

    float otherLeft   = other->x - half;
    float otherRight  = other->x + half;
    float otherTop    = other->y + half;
    float otherBottom = other->y - half;

    if (velocity_y > 0.0f &&
        thisBottom <= otherTop &&
        thisBottom >= otherTop - 20.0f &&
        thisRight > otherLeft &&
        thisLeft < otherRight)
    {
        y = otherTop + half;
        velocity_y = 0.0f;
        return;
    }

    if (thisRight >= otherLeft &&
        thisLeft < otherLeft &&
        thisTop > otherBottom &&
        thisBottom < otherTop)
    {
        x = otherLeft - half;
        return;
    }

    if (thisLeft <= otherRight &&
        thisRight > otherRight &&
        thisTop > otherBottom &&
        thisBottom < otherTop)
    {
        x = otherRight + half;
        return;
    }
}






