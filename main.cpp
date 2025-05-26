#include "Game.h"
#include "BasePet.h"
#include "BabyBird.h"
#include "BabyCat.h"
#include "BabyDog.h"
#include "Stats.h"
#include "Dog.h"
#include "Cat.h"
#include "Bird.h"

#include <string>

using namespace std;

int main() {
    
    Game game(nullptr);
    BasePet* pet = game.show_choice_menu();
    if (pet != nullptr){
        std::unique_ptr<BasePet> petPtr(pet);
        Game newGame(std::move(petPtr));

    }
    

    return 0;

}