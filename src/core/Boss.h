#pragma once
#include "AnimationWindow.h"

class Boss
{
    private:
        int upOrDown = 1;

    public:
        void updateBoss();
        TDT4102::Point TopLeftBoss = {290, 310};
        Boss(int _upOrDown);
    
    
};