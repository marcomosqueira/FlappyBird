#pragma once
#include <random>
class Pipes
{
    private:
        int mean1;
        int dev1;
        std::random_device rd;
        std::default_random_engine engine{rd()};
        std::normal_distribution<float> dist;
        int top_y;
        int bot_y;


    public:
        int getTopY() const;
        int getBotY() const;
        int pick_top_pipe_size();
        Pipes(int mean, int dev);

};
