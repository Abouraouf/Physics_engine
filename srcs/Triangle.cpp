#include "../headers/Triangle.hpp"
#include "../headers/Base.hpp"


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


bool Triangle::isClicked(int px, int py) {
    float halfBase = 60.0f;
    float topY = y + 40.0f;
    float bottomY = y - 60.0f;

    float Ax = x,      Ay = topY;      
    float Bx = x - halfBase, By = bottomY;  
    float Cx = x + halfBase, Cy = bottomY;  

    float v0x = Cx - Ax, v0y = Cy - Ay;
    float v1x = Bx - Ax, v1y = By - Ay;
    float v2x = px - Ax, v2y = py - Ay;


    float dot00 = v0x*v0x + v0y*v0y;
    float dot01 = v0x*v1x + v0y*v1y;
    float dot02 = v0x*v2x + v0y*v2y;
    float dot11 = v1x*v1x + v1y*v1y;
    float dot12 = v1x*v2x + v1y*v2y;

    float invDenom = 1.0f / (dot00 * dot11 - dot01 * dot01);
    float u = (dot11 * dot02 - dot01 * dot12) * invDenom;
    float v = (dot00 * dot12 - dot01 * dot02) * invDenom;

    return (u >= 0) && (v >= 0) && (u + v < 1);
}


void Triangle::put_in_middle()
{
    x = x_start;
    y = y_start;
    dragged = false;
    center = true;
}



void Triangle::apply_gravity(float dt)
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

void Triangle::checkCollision(Objects* Other) {
    Triangle* other = dynamic_cast<Triangle*>(Other);
    if (!other || other == this) return; 

    float halfBase = 60.0f;           
    float topY = other->y + 40.0f;    
    float bottomY = other->y - 60.0f; 

    float Ax = other->x, Ay = topY;
    float Bx = other->x - halfBase, By = bottomY;
    float Cx = other->x + halfBase, Cy = bottomY;

    float slopeAB = (By - Ay) / (Bx - Ax);
    float slopeAC = (Cy - Ay) / (Cx - Ax);

    float interceptAB = Ay - slopeAB * Ax;
    float interceptAC = Ay - slopeAC * Ax;

    float thisBottomX = x;
    float thisBottomY = y - 60.0f;

    if (thisBottomY >= bottomY) {
        if (thisBottomX >= Bx && thisBottomX <= Ax) {
            float edgeY = slopeAB * thisBottomX + interceptAB;
            if (thisBottomY <= edgeY) {
                y = edgeY + 60.0f;
                velocity_y = 0.0f;
            }
        }
        else if (thisBottomX >= Ax && thisBottomX <= Cx) {
            float edgeY = slopeAC * thisBottomX + interceptAC;
            if (thisBottomY <= edgeY) {
                y = edgeY + 60.0f;
                velocity_y = 0.0f;
            }
        }
    }
}

