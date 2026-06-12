#pragma once
#include "AnimationWindow.h"

class Bullet
{
    private:
        TDT4102::Point pos;

    public:
        Bullet(TDT4102::Point StartPos);
        void updatePos();
        TDT4102::Point getPos() const;


};