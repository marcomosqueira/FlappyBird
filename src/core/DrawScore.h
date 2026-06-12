#pragma once
#include "AnimationWindow.h"
class FlappyWindow;

class DrawScore
{
    private:
        int score; 
        static constexpr int numberWidth = 13;
        static constexpr int numberHeight = 20;
        static constexpr TDT4102::Point TopLeft_0 = {494,59};
        static constexpr TDT4102::Point TopLeft_1 = {134,454};
        static constexpr TDT4102::Point TopLeft_2 = {291,159};
        static constexpr TDT4102::Point TopLeft_3 = {305,159};
        static constexpr TDT4102::Point TopLeft_4 = {319,159};
        static constexpr TDT4102::Point TopLeft_5 = {333,159};
        static constexpr TDT4102::Point TopLeft_6 = {291,183};
        static constexpr TDT4102::Point TopLeft_7 = {305,183};
        static constexpr TDT4102::Point TopLeft_8 = {319,183};
        static constexpr TDT4102::Point TopLeft_9 = {333,183};
        static constexpr TDT4102::Point silverMedal = {111, 452};
        static constexpr TDT4102::Point goldMedal = {111, 476};
        static constexpr int medalDiameter = 23;

        static constexpr TDT4102::Point TopLeftMedal = {90,345};
        
        TDT4102::Point TopLeftScore = {300,327};
        TDT4102::Point TopLeftHighScore = {300,390};


    public:
        int highScore = 0;

        int getScore() const;
        void writeToScorefile(std::string scorefilepath) const;
        friend std::ostream& operator<<(std::ostream &os, const DrawScore& ds);
        std::shared_ptr<FlappyWindow> window = nullptr;
        void justScore();
        void updateScore();
        void DrawScoreNow();
        void DrawHighScore();
        void DrawMedal();
        DrawScore(int _score);


};