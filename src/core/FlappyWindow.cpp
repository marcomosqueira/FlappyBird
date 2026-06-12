#include "FlappyWindow.h"
#include "DrawScore.h"



FlappyWindow::FlappyWindow(TDT4102::Point position, int width, int height, const std::string& title):

AnimationWindow(position.x, position.y, width, height, title)

{
state = game_state::game;
poengsum = std::make_shared<int>((int)0);
}

game_state FlappyWindow::getGameState() const{
    return state;
}

void FlappyWindow::changeGameState(){
    if (state==game_state::game){
        state = game_state::menu;
    }
    else{
        state = game_state::game;
    }
    
}

void FlappyWindow::update_background_position(){
    if(pos_x_2==0){
        pos_x_1 = 0;
        pos_x_2 = 144*3;
    }
    
    draw_image_region({pos_x_1,0},bilde,width,height,{0,0},144,256);
    draw_image_region({pos_x_2,0},bilde,width,height,{0,0},144,256);
    
    
    
    pos_x_1 -= delta_x;
    pos_x_2 -= delta_x;
    if (quit_btn){
        if (state==game_state::game){
            quit_btn->setVisible(false);
            play_again->setVisible(false);
        }
        else{
            quit_btn->setVisible(true);
            play_again->setVisible(true);
        }
    }
        
}

void FlappyWindow::render_pipe_1(int top_pipe_size){
    if (pos_pipe_1 <= -pipe_width){
        pos_pipe_1 = 432;
    }
    if (pos_pipe_1 + pipe_width == bird->getxPos()+1){
        *poengsum += 1;
    }
    draw_image_region({pos_pipe_1,top_pipe_size-height},bilde,pipe_width,pipe_height,{55,322},27,161); 
    draw_image_region({pos_pipe_1,top_pipe_size+pipe_diff},bilde,pipe_width,pipe_height,{83,322},27,161);


    pos_pipe_1 -= 2*delta_x;
    
}

void FlappyWindow::render_pipe_2(int top_pipe_size){
    if(pos_pipe_2 <= -pipe_width){
        pos_pipe_2 = 432;
    }
    if (pos_pipe_2 + pipe_width == bird->getxPos()+1){
        *poengsum += 1;
    }
    draw_image_region({pos_pipe_2,top_pipe_size-height},bilde,pipe_width,pipe_height,{55,322},27,161); 
    draw_image_region({pos_pipe_2,top_pipe_size+pipe_diff},bilde,pipe_width,pipe_height,{83,322},27,161);
    pos_pipe_2 -= 2*delta_x;
}

bool FlappyWindow::checkCollision(int top_pipe_size_1, int top_pipe_size_2) const{
    std::vector<int> grenser = bird_limits();
    if ((grenser.at(0)<pos_pipe_1+pipe_width && grenser.at(1)>pos_pipe_1 && grenser.at(2)<top_pipe_size_1)||(grenser.at(0)<pos_pipe_1+pipe_width && grenser.at(1)>pos_pipe_1 && grenser.at(3)>top_pipe_size_1+pipe_diff)){
        return true;
    }
    if ((grenser.at(0)<pos_pipe_2+pipe_width && grenser.at(1)>pos_pipe_2 && grenser.at(2)<top_pipe_size_2)||(grenser.at(0)<pos_pipe_2+pipe_width && grenser.at(1)>pos_pipe_2 && grenser.at(3)>top_pipe_size_2+pipe_diff)){
        return true;
    }
    return false;
}

bool FlappyWindow::checkBulletCollisions(std::vector<Bullet> bullets) const{
    std::vector<int> grenser = bird_limits();
    for(Bullet &b : bullets){
        if ((grenser.at(0)<b.getPos().x && grenser.at(1)>b.getPos().x && grenser.at(2)<b.getPos().y && grenser.at(3)>b.getPos().y)){
        return true;
    }
    }
    return false;
}


void FlappyWindow::render_bird(TDT4102::Point Top_left_pos){
    int tall = *count_frames;
    std::string streng = std::to_string(tall);
    char digit = streng[streng.size()-1];
    
    if ((digit < '2' && digit >= '0') || (digit <= '9' && digit >= '8')){
        draw_image_region(Top_left_pos,bilde,width_bird,height_bird,{2,490},18,14);
    }
    else if ((digit < '4' && digit >= '2') || (digit < '8' && digit >= '6')){
        draw_image_region(Top_left_pos,bilde,width_bird,height_bird,{30,490},18,14);
    }
    else{
        draw_image_region(Top_left_pos,bilde,width_bird,height_bird,{58,490},18,14);
    }
    
}

void FlappyWindow::renderBoss(TDT4102::Point TopLeftPoint){
    int tall = *count_frames;
    std::string streng = std::to_string(tall);
    char digit = streng[streng.size()-2];
    
    if ((digit < '2' && digit >= '0') || (digit <= '9' && digit >= '8')){
        draw_image_region(TopLeftPoint,bilde,windowBossWidth,windowBossHeight,{114,380},sourceBossWidth,sourceBossHeight, TDT4102::FlipImage::HORIZONTAL);
    }
    else if ((digit < '4' && digit >= '2') || (digit < '8' && digit >= '6')){
        draw_image_region(TopLeftPoint,bilde,windowBossWidth,windowBossHeight,{114,406},sourceBossWidth,sourceBossHeight, TDT4102::FlipImage::HORIZONTAL);
    }
    else{
        draw_image_region(TopLeftPoint,bilde,windowBossWidth,windowBossHeight,{114,432},sourceBossWidth,sourceBossHeight, TDT4102::FlipImage::HORIZONTAL);
    }
}

void FlappyWindow::renderBullets(TDT4102::Point bulletPos){
    draw_image_region(bulletPos,bilde,14,14,{294,209},4,4);
}

std::vector<int> FlappyWindow::bird_limits() const{
    std::vector<int> grenser;
    grenser.push_back(bird->getxPos()+5);
    grenser.push_back(bird->getxPos()+width_bird-5);
    grenser.push_back(bird->getyPos()+5);
    grenser.push_back(bird->getyPos()+height_bird-5);
    return grenser;
}

void FlappyWindow::drawInfo(){
    draw_image_region({105,175},bilde,232,200,{293,87},58,53);
}


int FlappyWindow::getWindowHeight() const{
    return height;
}

int FlappyWindow::getWindowWidth() const{
    return width;
}

void FlappyWindow::afterGame(){
    draw_image_region({70, 202},bilde,game_over_width,game_over_height,{394,58},97,22);
    draw_image_region({48,280},bilde,info_width,info_height,{2,258},114,58);
    drawHelp->updateScore();
    drawHelp->DrawMedal();
    drawHelp->DrawScoreNow();
    drawHelp->DrawHighScore();
    if (quit_btn)
        return;
    quit_btn = std::make_unique<TDT4102::Button>((TDT4102::Point){48,500},(unsigned int)40*4,(unsigned int)40*3,(std::string)"Quit");
    play_again = std::make_unique<TDT4102::Button>((TDT4102::Point){230, 500},(unsigned int)40*4,(unsigned int)40*3,(std::string)"Play again!");
    add(*quit_btn);
    add(*play_again);
    quit_btn->setButtonColor(TDT4102::Color::blue);
    play_again->setButtonColor(TDT4102::Color::gold);
    quit_btn->setCallback(std::bind(&FlappyWindow::cb_quit,this));
    play_again->setCallback(std::bind(&FlappyWindow::play, this));

}
void FlappyWindow::cb_quit(){
    close();
}

void FlappyWindow::play(){
    state = game_state::game;
    *bird = Bird(400,0);
    pos_pipe_1 = 432;
    pos_pipe_2 = 432 + 250;
    *beginning = false;
    scores.push_back(*poengsum);
    *poengsum = 0;
    *write_check = true;
}

int FlappyWindow::getPosPipe1() const{
    return pos_pipe_1;
}

int FlappyWindow::getPosPipe2() const{
    return pos_pipe_2;
}

int FlappyWindow::getPipeWidth() const{
    return pipe_width;
}

int FlappyWindow::getBirdHeight() const{
    return height_bird;
}

int FlappyWindow::getBirdWidth() const{
    return width_bird;
}