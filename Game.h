#ifndef GAME_H
#define GAME_H

#include <string>
#include <memory>
#include "BasePet.h"

using namespace std;

class Game {

private:
  unique_ptr<BasePet> current_pet;
  bool running;
  
 

  void process_input(const string& input);
  void update(BasePet* pet);
  void end_game();

public:

 BasePet* show_choice_menu();
  Game(BasePet* pet);
  ~Game();  // destructor to delete pet pointer
  void start();
};

#endif