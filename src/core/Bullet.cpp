#include "Bullet.h"
#include <iostream>
Bullet::Bullet(TDT4102::Point StartPos){
    pos = StartPos;
}

void Bullet::updatePos(){
    pos.x -= 10;
}

TDT4102::Point Bullet::getPos() const{
    return pos;
}