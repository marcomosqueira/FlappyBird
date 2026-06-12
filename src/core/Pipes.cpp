#include "Pipes.h"

Pipes::Pipes(int mean, int dev)
{
mean1 = mean;
dev1 = dev;
dist=std::normal_distribution<float>{mean1, dev1};
}

int Pipes::getBotY() const{
    return bot_y;
}

int Pipes::getTopY() const{
    return top_y;
}

int Pipes::pick_top_pipe_size(){
    int size = dist(engine);
    top_y = size;
    bot_y = size + 140; //140 er pipe_diff
    return size;
}