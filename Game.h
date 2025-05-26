#ifndef GAME_H
#define GAME_H

#include <string>
#include <memory>
#include "BasePet.h"

using namespace std;

class Game {

private:
  unique_ptr<BasePet> current_pet;
  bool game_over;
  

  void show_main_menu();
  void show_choice_menu();

  void process_input( const string& input);
  void update();
  void end_game();

public:
  Game();
  Game();  // destructor to delete pet pointer
  void start();
};

#endif // GAME_H