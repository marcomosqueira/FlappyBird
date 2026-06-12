#pragma once

class Bird
{
    private:
        static constexpr double dt = 1.0/60.0;
        static constexpr double g = 9.81*54*4;
        double y_pos;
        double x_pos = 189;
        double y_speed;

    public:
        double getxPos() const;
        double getyPos() const;
        void update();
        void jump();
        bool check_pos(int windowHeight) const;
        Bird(double height, double speed=0);

};