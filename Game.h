#ifndef GAME_H
#define GAME_H

#include <string>
#include <memory>
#include "BasePet.h"

class Game {

private:
  std::unique_ptr<BasePet> current_pet;
  bool game_over;
  

    void show_main_menu();
    void show_choice_menu();

    void process_input( const std::string& input);
    void update();
    void end_game();

public:
    Game();
    ~Game();  // destructor to delete pet pointer
    void start();
};

#endif // GAME_H