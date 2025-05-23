#include "Dog.h"
#include <iostream>
#include <memory>

using namespace std;

// Constructor implementation
Dog::Dog(const string& name) : BasePet(name) { // Call BasePet constructor
    // Set starting stats specific to Dogs
    // For example, if BasePet has setters for happiness and hunger, call them here:
    // set_happiness(100);
    // set_hunger(50);
    // These values are chosen because dogs are generally happier but hungrier
Stats dog_stats;
dog_stats.set_hunger(50);
dog_stats.set_happiness(100);
dog_stats.set_health(100);
dog_stats.set_energy(80);
dog_stats.set_cleanliness(50);
set_stats(dog_stats); //gets dogs inital stats with BasePets setter
}

// This method is called to update the dog's status as the game progresses
void Dog::update_status() {
    std::cout << "Updating Dog Status...\n";
    Stats s = get_stats();
    s.change_hunger(5); //increased hunger
    s.change_happiness(-2);
    s.change_energy(-2);
    s.change_cleanliness(-5);
    s.change_health(5);

    set_stats(s);
}
    

// This method reacts to player actions (e.g., feed, play)
void Dog::perform_action(const string& action) {
     std::cout << "Dog performs action: " << action << endl;
    Stats s = get_stats();

    if(action =="feed"){
        s.change_hunger(-10);
        s.change_happiness(5);
        s.change_energy(5);
        std::cout << "You have fed the dog! It's wagging it's tail in happiness :)\n";
    }else if (action == "play"){
        s.change_happiness(10);
        s.change_hunger(5);
        s.change_energy(-10);
        std::cout << "You played with the dog. The dog is running around barking in happiness!\n";

    }else if (action == "clean"){
        s.change_cleanliness(10);
        s.change_hunger(-5);
        std::cout << "You washed the dog. He's covered in soapy bubbles!!\n";

    } else {
        std::cout << "Invalid action. Try again!\n";
    }

    set_stats(s);

    }
    
   
    // Modify stats here accordingly


// This checks if the dog is still alive
bool Dog::check_alive() const {
    Stats s = get_stats();
    std::cout << "Checking if Dog is alive based on health and hunger...\n";
    return s.get_hunger() < 100 && s.get_health() > 0;

    
}

// Check if the dog can evolve (e.g., reached certain age or happiness)
bool Dog::check_evolution() const {
    Stats s = get_stats();

    std::cout << "Checking if Dog meets evolution criteria...\n";
    return get_age() >= 13 && get_stats().get_happiness() >= 80;;
}

// Evolve returns a pointer to a new evolved pet or nullptr if no evolution
unique_ptr<BasePet> Dog::evolve() {
    if (check_evolution()) {
    std::cout << get_name() << "is evolving into next stage...\n";
    }
    // If evolution criteria met, create and return new evolved pet object
    return nullptr; // Placeholder: no evolution implemented yet
}

// Returns the string "Dog" identifying this pet type
string Dog::get_type() const {
    return "Dog";
}