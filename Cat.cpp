#include "Cat.h"
#include <iostream>
#include <memory>
using namespace std;

Cat::Cat(const string& name, int age) : BasePet(name, age) {
    Stats cat_stats;
    cat_stats.set_hunger(30);       // Cats start off less hungry
    cat_stats.set_happiness(70);    // Moderately happy
    cat_stats.set_health(90);       // Slightly fragile
    set_stats(cat_stats);
}

void Cat::update_status() {
    cout << "Updating Cat status...\n";
    Stats s = get_stats();
    s.change_hunger(4);        // Hunger increases
    s.change_happiness(-3);  
    s.change_energy(-2);
    s.change_cleanliness(-5);
    s.change_health(5); 
    set_stats(s);
}

void Cat::perform_action(const string& action) {
    Stats s = get_stats();

    if (action == "feed") {
        s.change_hunger(-8);
        s.change_happiness(4);
        std::cout << "You fed the cat. It purrs softly.\n";
    } else if (action == "pet") {
        s.change_happiness(6);
        s.change_cleanliness(-5);
        std::cout << "You pet the cat. It may or may not like it.\n";
    } else if (action == "play") {
        s.change_happiness(8);
        s.change_hunger(5);
        std::cout << "You played with the cat using a laser pointer. It was entertained.\n";
    } else if (action == "clean") {
        s.change_cleanliness(10);
        s.change_happiness(5);
        std::cout << "The cat licks itself clean.\n" ;
    } else {
        std::cout << "The cat stares at you blankly. (Unknown action)\n";
    }

    set_stats(s);
}

bool Cat::check_alive() const {
    Stats s = get_stats();
    return s.get_hunger() < 100 && s.get_health() > 0;
}

unique_ptr<BasePet> Cat::evolve() {
    if (check_evolution()) {
        cout << get_name() << "is evolving into next stage...\n";
    
    }
    return nullptr;
}

string Cat::get_type() const {
    return "Cat";
}
