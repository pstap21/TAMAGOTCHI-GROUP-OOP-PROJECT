#include "Dog.h"
#include <iostream>

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
    cout << "Updating Dog Status...\n";
    Stats s = get_stats();
    s.change_hunger(5); //increased hunger
    s.change_happiness(-2);
    s.change_energy(-2);
    s.change_cleanliness(-5);
    

 

    if (hunger > 100) hunger = 100;
    if (happiness < 0) happiness = 0;
    // Here you could decrease hunger over time, adjust happiness, etc.
    cout << "Updating Dog status: adjusting hunger and happiness levels over time.\n";
}

// This method reacts to player actions (e.g., feed, play)
void Dog::perform_action(const string& action) {
    // Implement logic based on the action string
    // Example: if action is "feed", reduce hunger
    cout << "Dog performs action: " << action << endl;
    // Modify stats here accordingly
}

// This checks if the dog is still alive
bool Dog::check_alive() const {
    // If hunger is too high or health too low, return false
    // Otherwise, true
    cout << "Checking if Dog is alive based on health and hunger...\n";
    return hunger < 100 && health > 0; // Placeholder: replace with actual checks
}

// Check if the dog can evolve (e.g., reached certain age or happiness)
bool Dog::check_evolution() const {
    // Return true if criteria met
    cout << "Checking if Dog meets evolution criteria...\n";
    return false; // Placeholder: no evolution implemented yet
}

// Evolve returns a pointer to a new evolved pet or nullptr if no evolution
unique_ptr<BasePet> Dog::evolve() {
    cout << "Evolving Dog into next stage...\n";
    // If evolution criteria met, create and return new evolved pet object
    return nullptr; // Placeholder: no evolution implemented yet
}

// Returns the string "Dog" identifying this pet type
string Dog::get_type() const {
    return "Dog";
}