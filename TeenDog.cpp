#include "TeenDog.h"
#include "AdultDog.h"
#include "BasePet.h"
#include "Stats.h"
#include <iostream>
#include <memory>

using namespace std;

TeenDog::TeenDog (const string&name) : Dog(name, 5) {
    //evolution stats
    Stats teen_stats;
    teen_stats.set_hunger(40);
    teen_stats.set_happiness(90);
    teen_stats.set_health(100);
    teen_stats.set_energy(90);
    teen_stats.set_cleanliness(60);
    set_stats(teen_stats);


}
void TeenDog::update_status() {
    Stats s = get_stats();
    s.change_hunger(0);
    s.change_happiness(0);
    s.change_energy(0);
    s.change_cleanliness(0);
    s.change_health(0);
    set_stats(s);
    age++;
}

void TeenDog::perform_action(const string&action) {
    Stats s = get_stats();

    if(action == "feed") {
        s.change_hunger(8);
        s.change_happiness(4);
        s.change_energy(-3);
        cout << "You fed" << get_name() << " " << ". Its growing big and strong!\n";
    } else if (action == "play") {
        s.change_happiness(8);
        s.change_energy(-8);
        cout << "You played with" <<get_name() << " " << ". It ran around with lots of energy!\n";
    } else if(action == "clean") {
        s.change_cleanliness(10);
        s.change_energy(5);
        cout << "You washed" << get_name() << " " << ". They are now sparkling clean!!\n";
    } else  {
        cout << "Action not supported, try again.\n";
    }
    set_stats(s);

    }
    bool TeenDog::check_alive() const {
    Stats s = get_stats();
    return s.get_hunger() <= 100 && s.get_health() >= 0;

    }

    bool TeenDog::check_evolution() const {
    return get_age() >= 15 && get_stats().get_happiness() >= 90 && get_stats().get_cleanliness() >= 90;
}

unique_ptr<BasePet> TeenDog::evolve() {
    if(check_evolution()) {
        cout << get_name() << " is evolving into an adult dog!!\n";
        return make_unique<AdultDog>(get_name());
    }
    return nullptr;
}

string TeenDog::get_type() const {
    return "Teen Dog";
}