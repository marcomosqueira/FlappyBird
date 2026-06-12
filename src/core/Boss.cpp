#include "Boss.h"

Boss::Boss(int _upOrDown){
    upOrDown = _upOrDown;
}

void Boss::updateBoss(){
    if (TopLeftBoss.y>700){
        upOrDown = -1;
    }
    if (TopLeftBoss.y <70){
        upOrDown = 1;
    }
    TopLeftBoss.y += upOrDown*8;
}
