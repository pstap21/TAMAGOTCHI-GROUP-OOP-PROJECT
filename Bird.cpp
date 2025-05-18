#include "Bird.h"
#include <iostream>

using namespace std;

// Constructor implementation
Bird::Bird(const string& name) : BasePet(name) { // Call BasePet constructor, age 0
    // Set starting stats specific to Birds
    // For example, if BasePet has setters for happiness and hunger, call them here:
    // set_happiness(100);
    // set_hunger(50);
}

// This method is called to update the dog's status as the game progresses
void Bird::update_status() {
    // Here you could decrease hunger over time, adjust happiness, etc.
    cout << "Updating Bird status: adjusting hunger and happiness levels over time.\n";
}

// This method reacts to player actions (e.g., feed, play)
void Bird::perform_action(const string& action) {
    // Implement logic based on the action string
    // Example: if action is "feed", reduce hunger
    cout << "Bird performs action: " << action << endl;
    // Modify stats here accordingly
}

// This checks if the bird is still alive
bool Bird::check_alive() const {
    // If hunger is too high or health too low, return false
    // Otherwise, true
    cout << "Checking if Bird is alive based on health and hunger...\n";
    return true; // Placeholder: replace with actual checks
}

// Check if the bird can evolve (e.g., reached certain age or happiness)
bool Bird::check_evolution() const {
    // Return true if criteria met
    cout << "Checking if Bird meets evolution criteria...\n";
    return false; // Placeholder: no evolution implemented yet
}

// Evolve returns a pointer to a new evolved pet or nullptr if no evolution
unique_ptr<BasePet> Bird::evolve() {
    cout << "Evolving Bird into next stage...\n";
    // If evolution criteria met, create and return new evolved pet object
    return nullptr; // Placeholder: no evolution implemented yet
}

// Returns the string "Bird" identifying this pet type
string Bird::get_type() const {
    return "Bird";
}
