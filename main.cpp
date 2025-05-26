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
    

    static BasePet* pet = Game::show_choice_menu();
    // static BasePet* pet = Game::show_main_menu();
    
    if (pet != nullptr){
        std::unique_ptr<BasePet> petPtr(pet);
        Game game { std::move(petPtr) };
    game.start();
    }
    

    return 0;

}