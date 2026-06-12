#include "DrawScore.h"
#include "FlappyWindow.h"
#include <fstream>
#include <filesystem>

DrawScore::DrawScore(int _score)
{
    score = _score;
}

void DrawScore::updateScore(){
    int tell = 0;
    score = *window->poengsum;
    for (int x:window->scores){
        if (score> x){
            tell += 1;
        }
    }
    if (tell == window->scores.size()){
        highScore = score;
    }
    
}

void DrawScore::DrawMedal(){
    if (score >= 10 && score < 20){
        window->draw_image_region(TopLeftMedal, window->bilde, medalDiameter*3, medalDiameter*3, silverMedal, medalDiameter, medalDiameter);
    }
    if (score >= 20){
        window->draw_image_region(TopLeftMedal, window->bilde, medalDiameter*3,medalDiameter*3,goldMedal,medalDiameter,medalDiameter);
    }
}

void DrawScore::DrawScoreNow(){
    std::string poeng = std::to_string(score);
    for(int i = 0; i<poeng.size(); ++i){
            TopLeftScore.x =290+ i*(numberWidth+10) ;
            if (poeng.at(i)=='0'){
                window->draw_image_region(TopLeftScore,window->bilde,(int)numberWidth*2,(int)numberHeight*2,TopLeft_0,numberWidth,numberHeight);
            }
            else if (poeng.at(i) == '1'){
                window->draw_image_region(TopLeftScore,window->bilde,(int)numberWidth*2,(int)numberHeight*2,TopLeft_1,numberWidth,numberHeight);
            }
            else if (poeng.at(i) == '2'){
                window->draw_image_region(TopLeftScore,window->bilde,(int)numberWidth*2,(int)numberHeight*2,TopLeft_2,numberWidth,numberHeight);
            }
            else if (poeng.at(i) == '3'){
                window->draw_image_region(TopLeftScore,window->bilde,(int)numberWidth*2,(int)numberHeight*2,TopLeft_3,numberWidth,numberHeight);
            }
            else if (poeng.at(i) == '4'){
                window->draw_image_region(TopLeftScore,window->bilde,(int)numberWidth*2,(int)numberHeight*2,TopLeft_4,numberWidth,numberHeight);
            }
            else if (poeng.at(i) == '5'){
                window->draw_image_region(TopLeftScore,window->bilde,(int)numberWidth*2,(int)numberHeight*2,TopLeft_5,numberWidth,numberHeight);
            }
            else if (poeng.at(i) == '6'){
                window->draw_image_region(TopLeftScore,window->bilde,(int)numberWidth*2,(int)numberHeight*2,TopLeft_6,numberWidth,numberHeight);
            }
            else if (poeng.at(i) == '7'){
                window->draw_image_region(TopLeftScore,window->bilde,(int)numberWidth*2,(int)numberHeight*2,TopLeft_7,numberWidth,numberHeight);
            }
            else if (poeng.at(i) == '8'){
                window->draw_image_region(TopLeftScore,window->bilde,(int)numberWidth*2,(int)numberHeight*2,TopLeft_8,numberWidth,numberHeight);
            }
            else{
                window->draw_image_region(TopLeftScore,window->bilde,(int)numberWidth*2,(int)numberHeight*2,TopLeft_9,numberWidth,numberHeight);
            }
            
    }
    
}

void DrawScore::DrawHighScore(){
    std::string poeng = std::to_string(highScore);
    for (int i = 0; i< poeng.size(); ++i){
        TopLeftHighScore.x =290+i*(numberWidth+10);
        if (poeng.at(i)=='0'){
            window->draw_image_region(TopLeftHighScore,window->bilde,(int)numberWidth*2,(int)numberHeight*2,TopLeft_0,numberWidth,numberHeight);
        }
        else if (poeng.at(i) == '1'){
            window->draw_image_region(TopLeftHighScore,window->bilde,(int)numberWidth*2,(int)numberHeight*2,TopLeft_1,numberWidth,numberHeight);
        }
        else if (poeng.at(i) == '2'){
            window->draw_image_region(TopLeftHighScore,window->bilde,(int)numberWidth*2,(int)numberHeight*2,TopLeft_2,numberWidth,numberHeight);
        }
        else if (poeng.at(i) == '3'){
            window->draw_image_region(TopLeftHighScore,window->bilde,(int)numberWidth*2,(int)numberHeight*2,TopLeft_3,numberWidth,numberHeight);
        }
        else if (poeng.at(i) == '4'){
            window->draw_image_region(TopLeftHighScore,window->bilde,(int)numberWidth*2,(int)numberHeight*2,TopLeft_4,numberWidth,numberHeight);
        }
        else if (poeng.at(i) == '5'){
            window->draw_image_region(TopLeftHighScore,window->bilde,(int)numberWidth*2,(int)numberHeight*2,TopLeft_5,numberWidth,numberHeight);
        }
        else if (poeng.at(i) == '6'){
            window->draw_image_region(TopLeftHighScore,window->bilde,(int)numberWidth*2,(int)numberHeight*2,TopLeft_6,numberWidth,numberHeight);
        }
        else if (poeng.at(i) == '7'){
            window->draw_image_region(TopLeftHighScore,window->bilde,(int)numberWidth*2,(int)numberHeight*2,TopLeft_7,numberWidth,numberHeight);
        }
        else if (poeng.at(i) == '8'){
            window->draw_image_region(TopLeftHighScore,window->bilde,(int)numberWidth*2,(int)numberHeight*2,TopLeft_8,numberWidth,numberHeight);
        }
        else{
            window->draw_image_region(TopLeftHighScore,window->bilde,(int)numberWidth*2,(int)numberHeight*2,TopLeft_9,numberWidth,numberHeight);
        }
    }
    

}

int DrawScore::getScore() const{
    return score;
}

void DrawScore::justScore(){
    score = *window->poengsum;
}
std::ostream& operator<<(std::ostream &os, const DrawScore& ds){
    if (ds.score > ds.highScore){
        os <<"Den nye highscoren er: "<< ds.score << "!!!"<<std::endl;
    }
    else{
        os<<"Scoren ble: "<<ds.score<<std::endl;
    }
    return os;
    
}

void DrawScore::writeToScorefile(std::string scorefilepath) const{
    std::filesystem::path file{scorefilepath};
    if (!std::filesystem::exists(file)){
        throw std::runtime_error("This file does not exist");
    }
    std::ofstream filstrøm{file, std::ios::app};
    filstrøm<<*this;
}