#pragma once

#include "AnimationWindow.h"
#include "widgets/Button.h"
#include "Bird.h"
#include <memory>
#include "Bullet.h"
#include "Bullets.h"
class DrawScore;



enum class game_state{game, menu};

class FlappyWindow: public TDT4102::AnimationWindow
{
    private:
        game_state state;
        int pos_x_1 = 0;
        int pos_x_2 = 144*3;
        int pos_pipe_1 = 432;
        int pos_pipe_2 = 432 + 250;
        static constexpr int delta_x = 1;
        static constexpr int width = 144*3;
        static constexpr int height = 256*3;
        static constexpr int width_bird = 18*3;
        static constexpr int height_bird = 14*3;
        static constexpr int game_over_height = 22*3;
        static constexpr int game_over_width = 97*3;
        static constexpr int info_height = 58*3;
        static constexpr int info_width = 114*3;
        static constexpr int pipe_width = 100;
        static constexpr int pipe_height = 768;
        static constexpr int pipe_diff = 165;

        static constexpr int windowBossWidth = 18*8;
        static constexpr int windowBossHeight = 13*8;
        static constexpr int sourceBossWidth = 18;
        static constexpr int sourceBossHeight = 13;
        
        public:
        std::shared_ptr<Bullets> bul;
        void renderBoss(TDT4102::Point TopLeftPoint);
        void renderBullets(TDT4102::Point bulletPos);
        bool checkBulletCollisions(std::vector<Bullet> bullets) const;
        std::shared_ptr<bool> write_check;
        std::shared_ptr<int> count_frames;
        std::vector<int> scores;
        std::shared_ptr<DrawScore> drawHelp;
        TDT4102::Image bilde = TDT4102::Image("assets/flappy_bird_sprites.png");
        std::shared_ptr<int> poengsum = nullptr;
        bool checkCollision(int top_pipe_size_1, int top_pipe_size_2) const;
        std::vector<int> bird_limits() const;
        std::shared_ptr<bool> beginning;
        std::shared_ptr<Bird> bird;
        std::unique_ptr<TDT4102::Button> quit_btn = nullptr;
        std::unique_ptr<TDT4102::Button> play_again = nullptr;
        int getPosPipe1() const;
        int getPosPipe2() const;
        int getPipeWidth() const;
        int getBirdWidth() const;
        int getBirdHeight() const;
        void drawInfo();
        void cb_quit();
        void play();
        int getWindowHeight() const;
        int getWindowWidth() const;
        game_state getGameState() const;
        void changeGameState();
        void update_background_position();
        void render_bird(TDT4102::Point Top_left_pos);
        void render_pipe_1(int top_pipe_size);
        void render_pipe_2(int top_pipe_size);
        void afterGame();
        FlappyWindow(TDT4102::Point position, int width, int height, const std::string& title);

};

