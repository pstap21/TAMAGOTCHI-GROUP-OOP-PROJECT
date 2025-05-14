#ifndef GAME_H
#define GAME_H

#include "BasePet.h"

class Game {
    private:

    std::unique_ptr<BasePet> pet;
    bool is_running;

    void show_main_menu();
    void process_input( const std::string& input);
    void update();
    void end_game();

    public:

    Game();
    void start();


};

#endif