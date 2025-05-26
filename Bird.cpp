#include "Bird.h"
#include <iostream>
#include <memory>
using namespace std;

// Constructor implementation
Bird::Bird(const string& name, int age) : BasePet(name, age) { // Call BasePet constructor
  Stats bird_stats;
  bird_stats.set_hunger(20);
  bird_stats.set_happiness(60);
  bird_stats.set_health(85);
  bird_stats.set_cleanliness(50);
  bird_stats.set_energy(70);
  set_stats(bird_stats);
}

// This method is called to update the dog's status as the game progresses
void Bird::update_status() {
    // Here you could decrease hunger over time, adjust happiness, etc.
    cout << "Updating Bird status: adjusting stats over time.\n";
    Stats s = get_stats();
    s.change_hunger(3);
    s.change_happiness(-2);
    s.change_energy(5);
    s.change_cleanliness(10);
    set_stats(s);
    age++;
}

// This method reacts to player actions (e.g., feed, play)
void Bird::perform_action(const string& action) {
   Stats s = get_stats();

    if (action == "feed") {
        s.change_hunger(-6);
        s.change_happiness(3);
        cout << "You fed the bird. It chirps happily!!\n";
    } else if (action == "sing") {
        s.change_happiness(7);
        cout << "You sang to the bird. It chirped along!\n";
    } else if (action == "fly") {
        s.change_happiness(5);
        s.change_hunger(4);
        s.change_energy(-5);
        cout << "You let the bird fly around. It feels free.\n";
    } else if (action == "sleep") {
        s.change_energy(10);
        s.change_happiness(5);
        cout << "The bird rests its head in its wing and falls asleep...zzzz\n";
    }else {
        cout << "The bird tilts its head, confused. (Unknown action)\n";
    }

    set_stats(s);
   
}

// This checks if the bird is still alive
bool Bird::check_alive() const {
    Stats s = get_stats();
    cout << "Checking if Bird is alive based on health and hunger...\n";
    return s.get_hunger() < 100 && s.get_health() > 0; 
}

// Evolve returns a pointer to a new evolved pet or nullptr if no evolution
unique_ptr<BasePet> Bird::evolve() {
    if (check_evolution()) {
    cout << get_name() << "is evolving into next stage...\n";
    }
    // If evolution criteria met, create and return new evolved pet object
    return nullptr; 
}

// Returns the string "Bird" identifying this pet type
string Bird::get_type() const {
    return "Bird";
}
