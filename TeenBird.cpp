#include "TeenBird.h"
#include "AdultBird.h"
#include "BasePet.h"
#include "Stats.h"
#include <iostream>
#include <memory>

using namespace std;

TeenBird::TeenBird (const string&name) : BasePet(name) {
    //evolution stats
    Stats teen_stats;
    teen_stats.set_hunger(40);
    teen_stats.set_happiness(90);
    teen_stats.set_health(100);
    teen_stats.set_energy(90);
    teen_stats.set_cleanliness(60);
    set_stats(teen_stats);


}
void TeenBird::update_status() {
    Stats s = get_stats();
    s.change_hunger(4);
    s.change_happiness(-3);
    s.change_energy(-4);
    s.change_cleanliness(-4);
    s.change_health(-2);
    set_stats(s);
}

void TeenBird::perform_action(const string&action) {
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
    bool TeenBird::check_alive() const {
    Stats s = get_stats();
    return s.get_hunger() < 100 && s.get_health() > 0;

    }

    bool TeenBird::check_evolution() const {
    
    return get_age() >=30 && get_stats().get_happiness() >= 90;
}

unique_ptr<BasePet> TeenBird::evolve() {
    if(check_evolution()) {
        std::cout << get_name() << "is evolving into an adult bird!!\n";
        return std::make_unique<AdultBird>(get_name());
    }
    return nullptr;
}

string TeenBird::get_type() const {
    return "Teen Bird";
}