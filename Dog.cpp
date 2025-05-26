#include "Dog.h"
#include <iostream>
#include <memory>

using namespace std;

Dog::Dog(const string& name, int age) : BasePet(name, age) {
    Stats dog_stats;
    dog_stats.set_hunger(50);       
    dog_stats.set_happiness(90);    
    dog_stats.set_health(100);       
    set_stats(dog_stats);
}

void Dog::update_status() {
    cout << "Updating dog status...\n";
    Stats s = get_stats();
    s.change_hunger(4);        
    s.change_happiness(-3);  
    s.change_energy(-2);
    s.change_cleanliness(-5);
    s.change_health(5); 
    set_stats(s);
    age++;
}

void Dog::perform_action(const string& action) {
    Stats s = get_stats();

    if (action == "feed") {
        s.change_hunger(-8);
        s.change_happiness(4);
        std::cout << "You fed the dog. It wags its tail.\n";
    } else if (action == "pet") {
        s.change_happiness(6);
        s.change_cleanliness(-5);
        std::cout << "You pet the dog. It may or may not like it.\n";
    } else if (action == "play") {
        s.change_happiness(8);
        s.change_hunger(5);
        std::cout << "You played with the dog. It was entertained.\n";
    } else if (action == "clean") {
        s.change_cleanliness(10);
        s.change_happiness(5);
        std::cout << "The dog licks itself clean.\n" ;
    } else {
        std::cout << "The dog stares at you blankly. (Unknown action)\n";
    }

    set_stats(s);
}

bool Dog::check_alive() const {
    Stats s = get_stats();
    return s.get_hunger() < 100 && s.get_health() > 0;
}

unique_ptr<BasePet> Dog::evolve() {
    if (check_evolution()) {
        cout << get_name() << "is evolving into next stage...\n";
    
    }
    return nullptr;
}

string Dog::get_type() const {
    return "Dog";
}