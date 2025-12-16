#pragma once
#include "Objects.hpp"

class Triangle : public Objects {
public:
    Triangle();
    void draw() override;

    // mmoovement
    bool isClicked(int mx, int my) override;
    void startDrag(int mx, int my) override;
    void stopDrag() override;
    void dragTo(int mx, int my) override;
    void put_in_middle() override;

    //gravity
    void apply_gravity(float dt) override;
    
    //collisions
    void checkCollision(Objects* Other) override;
    
    ~Triangle() override {};
};