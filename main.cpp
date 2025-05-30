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
    Game game(nullptr);  // Create a Game object with nullptr first

    // Show the adoption menu and get a pet from user choice
    auto pet = game.show_choice_menu();
    if (!pet) {
        std::cout << "No valid pet chosen. Exiting.\n";
        return 1;  // exit if user didn't choose a pet
    }

    // Now create the Game with the chosen pet
    Game game_with_pet(std::move(pet));

    // Start the game loop
    game_with_pet.start();

    return 0;
}



// int main() {
    

//     static BasePet* pet = Game::show_choice_menu();
//     // static BasePet* pet = Game::show_main_menu();
    
//     if (pet != nullptr){
//         std::unique_ptr<BasePet> petPtr(pet);
//         Game game { std::move(petPtr) };
//     game.start();
//     }
    

//     return 0;

// }