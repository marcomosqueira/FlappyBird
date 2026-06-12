#include "FlappyBird.h"
#include <iostream>
FlappyBird::FlappyBird() : pipe{310, 100}, boss1{1}, boss2{-1}
{

    vindu = std::make_shared<FlappyWindow>((TDT4102::Point){50, 50}, (int)vindu->getWindowWidth(), (int)vindu->getWindowHeight(), "Flappybird");
    score = vindu->poengsum;
    tegneHjelp = std::make_shared<DrawScore>(*score);
    tegneHjelp->window = vindu;
    vindu->drawHelp = tegneHjelp;
    fugl = std::make_shared<Bird>(400.0, 0.0);
    vindu->bird = fugl;
    start = std::make_shared<bool>(false);
    bullets = std::make_shared<Bullets>(std::vector<Bullet>{});
    vindu->bul = bullets;
    vindu->beginning = start;
    vindu->write_check = write;
    vindu->count_frames = count;
}

void FlappyBird::run()
{

    while (!vindu->should_close())
    {
        *count += 1;
        tegneHjelp->justScore();

        vindu->update_background_position();
        if (!*start)
        {
            vindu->drawInfo();
        }
        if (vindu->is_key_down(KeyboardKey::SPACE))
        {
            *start = true;
        }
        if (vindu->getGameState() == game_state::game)
        {
            if (*start)
            {
                if (pipe_1_check == false)
                {
                    top_pipe_size_1 = pipe.pick_top_pipe_size();
                    pipe_1_check = true;
                }
                if (vindu->getPosPipe1() <= -vindu->getPipeWidth())
                {
                    pipe_1_check = false;
                }
                vindu->render_pipe_1(top_pipe_size_1);

                if (pipe_2_check == false)
                {
                    top_pipe_size_2 = pipe.pick_top_pipe_size();
                    pipe_2_check = true;
                }
                if (vindu->getPosPipe2() <= -vindu->getPipeWidth())
                {
                    pipe_2_check = false;
                }
                vindu->render_pipe_2(top_pipe_size_2);

                fugl->update();
            }
        }
        if (vindu->getGameState() == game_state::game)
        {
            vindu->render_bird({(int)fugl->getxPos(), (int)fugl->getyPos()});
        }
        if (vindu->is_key_down(KeyboardKey::SPACE))
        {
            if (space_check == false)
            {
                space_check = true;
                fugl->jump();
                vindu->play_audio(game_sound);
            }
        }
        else
        {
            space_check = false;
        }

        if (vindu->getGameState() == game_state::menu)
        {
            try
            {
                if (*write)
                {
                    tegneHjelp->justScore();
                    tegneHjelp->writeToScorefile("scoreboard/scoreboard.txt");
                    *write = false;
                }
            }
            catch (std::runtime_error e)
            {
                std::cout << e.what() << std::endl;
                vindu->close();
            }
            vindu->afterGame();
            if (music)
            {
                vindu->play_audio(lobby_music);
                music = false;
            }
        }
        else
        {
            music = true;
            if (!fugl->check_pos(vindu->getWindowHeight()))
            {
                vindu->changeGameState();
            }
            if (vindu->checkCollision(top_pipe_size_1, top_pipe_size_2))
            {
                vindu->changeGameState();
            }
        }
        if (tegneHjelp->getScore() > 50)
        {   *count = 10;
            while (!vindu->should_close())
            {
                if (*count == 900){
                    while (!vindu->should_close())
                    {
                        vindu->update_background_position();
                        if (final_music){
                            vindu->play_audio(lobby_music);
                            final_music = false;
                        }
                        vindu->draw_text({50,345}, "Du har rundet spillet!",TDT4102::Color::black,40U);
                        vindu->next_frame();
                    }
                } 
                *count += 1;
                vindu->update_background_position();
                fugl->update();
                if (vindu->is_key_down(KeyboardKey::SPACE))
                {
                    if (space_check == false)
                    {
                        space_check = true;
                        fugl->jump();
                        vindu->play_audio(game_sound);
                    }
                }
                else
                {
                    space_check = false;
                }
                boss1.updateBoss();
                boss2.updateBoss();
                vindu->renderBoss(boss1.TopLeftBoss);
                vindu->renderBoss(boss2.TopLeftBoss);
                vindu->render_bird({(int)fugl->getxPos(), (int)fugl->getyPos()});
                if (!fugl->check_pos(vindu->getWindowHeight()))
                {
                    vindu->close();
                }
                std::string tall = std::to_string(*count);
                if(tall[tall.size()-2]=='5'){
                    TDT4102::Point b1 = boss1.TopLeftBoss;
                    TDT4102::Point b2 = boss2.TopLeftBoss;
                    Bullet bu_1{b1};
                    Bullet bu_2{b2};
                    bullets->add_bullets({bu_1,bu_2});
                }
                bullets->update_pos();
                for (Bullet b : bullets->kuler){
                    vindu->renderBullets(b.getPos());
                }
                if(vindu->checkBulletCollisions(bullets->kuler)){
                    vindu->close();
                }
                vindu->next_frame();
            }
        }
        vindu->next_frame();
    }
}