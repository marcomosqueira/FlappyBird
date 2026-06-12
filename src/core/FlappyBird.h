#pragma once
#include "FlappyWindow.h"
#include "Bird.h"
#include "Pipes.h"
#include "DrawScore.h"
#include "Boss.h"
#include "Bullet.h"
#include "Bullets.h"

class FlappyBird
{
    private:
        std::shared_ptr<Bullets> bullets;  
        std::shared_ptr<int> score = nullptr;
        std::shared_ptr<DrawScore> tegneHjelp = nullptr;
        std::shared_ptr<bool> start = nullptr;
        std::shared_ptr<FlappyWindow> vindu = nullptr;
        Pipes pipe;
        Boss boss1;
        Boss boss2;
        std::shared_ptr<Bird> fugl=nullptr;
        bool space_check = false;
        bool pipe_1_check = false;
        bool pipe_2_check = false;
        int top_pipe_size_1;
        int top_pipe_size_2;
        std::shared_ptr<bool> write = std::make_shared<bool>(true);
        std::shared_ptr<int> count = std::make_shared<int>(10);

        TDT4102::Audio lobby_music = TDT4102::Audio("assets/lobby_music.mp3");
        TDT4102::Audio game_sound = TDT4102::Audio("assets/flap_sound.mp3");
        bool music = true;
        bool final_music = true;
    public:
        
        void run();
        FlappyBird();


};