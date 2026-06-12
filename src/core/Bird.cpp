#include "Bird.h"

Bird::Bird(double height, double speed)
{
y_pos = height;
y_speed = speed;
}

void Bird::update(){
    y_speed += g*dt;
    y_pos += y_speed*dt;
}

void Bird::jump(){
    y_speed = -600;
}

double Bird::getyPos() const{
    return y_pos;
}

double Bird::getxPos() const{
    return x_pos;
}

bool Bird::check_pos(int windowHeight) const{
    return y_pos<windowHeight && y_pos>0;
}