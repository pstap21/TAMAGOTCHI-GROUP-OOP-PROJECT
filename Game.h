#ifndef GAME_H
#define GAME_H

#include <string>
#include <memory>
#include "BasePet.h"

using namespace std;

class Game {

private:
  std::unique_ptr<BasePet> current_pet;
  bool running;
  

  void process_input(const string& input);
  void update(BasePet* pet);
  void end_game();

public:

explicit Game(std::unique_ptr<BasePet> pet);

 static BasePet* show_choice_menu();
 static BasePet* show_main_menu();

void start();
  ~Game();
   // destructor to delete pet pointer
  
};

#endif