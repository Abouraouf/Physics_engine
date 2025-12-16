#include "../headers/Objects.hpp"
#include "../headers/Triangle.hpp"
#include "../headers/Square.hpp"
#include "../headers/Window.hpp"
#include "../headers/Base.hpp"

Objects::Objects()
    : x(0.0f), y(0.0f),
      width(1.0f), height(1.0f),
      r(0.5f), g(0.5f), b(0.5f),
      type("unknown"),
      state(0)
{}

void Objects::update(float dt) {
    if (!dragged && center) {
        apply_gravity(dt);
        for (auto obj : g_base->objects){
            if (obj->type == "Triangle")
            {
                Triangle* target = dynamic_cast<Triangle*>(obj);
                if (target && target != this) {
                    checkCollision(target);
                }
            }
            else
            {
                Square* target = dynamic_cast<Square*>(obj);
                if (target && target != this) {
                    checkCollision(target);
                }
            }
        }
    }
}

Objects::~Objects(){}
