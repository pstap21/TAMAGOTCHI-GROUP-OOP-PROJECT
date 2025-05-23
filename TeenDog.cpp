#include "TeenDog.h"
#include <iostream>
#include <memory>

using namespace std;

TeenDog::TeenDog (const string&name) : BasePet(name) {
    //evolution stats
    Stats teen_stats;
    teen_stats.set_hunger(40);
    teen_stats.set_happiness(90);
    teen_stats.set_health(100);
    teen_stats.set_energy(90);
    teen_stats.set_cleanliness(60);
    set_stats(teen_stats);

    cout << name << "has evolved into a Teen Dog!\n";


}

void TeenDog::perform_action(const string&action) {
    Stats s = get_stats();

    if(action == "feed") {
        s.change_hunger(-8);
        s.change_happiness(4);
        s.change_energy(3);
        cout << "You fed" << get_name() << " " << ". Its growing big and strong!\n";
    } else if (action == "play") {
        s.change_happiness(8);
        s.change_energy(-8);
        cout << "You played with" <<get_name() << " " << ". It ran around with lots of energy!\n";
    } else if(action == "clean") {
        s.change_cleanliness(10);
        cout << "You washed" << get_name() << " " << ". They are now sparkling clean!!\n";
    } else  {
        "Action not supported, try again.\n";
    }
    set_stats(s);

    }
    bool TeenDog::check_evolution() const {
    // add adult dog evolution
    return false;
}

unique_ptr<BasePet> TeenDog::evolve() {
    // add adult dog evolution
    return nullptr;
}

string TeenDog::get_type() const {
    return "Teen Dog";
}