#include "Bullets.h"



Bullets::Bullets(std::vector<Bullet> bullets){
    for(Bullet b : bullets){
        kuler.push_back(b);
    }
}

void Bullets::update_pos(){
    for(Bullet &b : kuler){
        b.updatePos(); 
    }
}

void Bullets::add_bullets(std::vector<Bullet> bullets){
    for(Bullet b : bullets){
        kuler.push_back(b);
    }
}