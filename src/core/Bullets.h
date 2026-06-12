#pragma once
#include "AnimationWindow.h"
#include "Bullet.h"

class Bullets
{
    private:
        

    public:
        std::vector<Bullet> kuler;
        void update_pos();
        void add_bullets(std::vector<Bullet> bullets);
        Bullets(std::vector<Bullet> bullets);

};