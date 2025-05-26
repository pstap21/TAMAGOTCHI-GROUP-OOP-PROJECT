#include "AdultCat.h"
#include "BasePet.h"
#include "Stats.h"
#include "Cat.h"
#include <iostream>
#include <memory>

AdultCat::AdultCat(const string& name) : Cat(name, 15) {
    Stats stats;
    stats.set_hunger(30);
    stats.set_happiness(85);
    stats.set_health(100);
    stats.set_energy(100);
    stats.set_cleanliness(70);
    set_stats(stats);
}

void AdultCat::update_status() {
    Stats s = get_stats();
    s.change_hunger(4);
    s.change_happiness(-1);
    s.change_energy(-3);
    s.change_cleanliness(-4);
    set_stats(s);
    age++;
}

void AdultCat::perform_action(const string& action) {
    Stats s = get_stats();

    if (action == "feed") {
        s.change_hunger(-15);
        s.change_happiness(4);
    } else if (action == "play") {
        s.change_happiness(8);
        s.change_energy(-12);
        s.change_hunger(3);
    } else if (action == "clean") {
        s.change_cleanliness(12);
        s.change_happiness(1);
    } else {
        std::cout << "Invalid action for Adult Cat.\n";
    }

    set_stats(s);
}

bool AdultCat::check_alive() const {
    Stats s = get_stats();
    return s.get_hunger() < 100 && s.get_health() > 0;
}

bool AdultCat::check_evolution() const {
    // No further evolution
    return false;
}

unique_ptr<BasePet> AdultCat::evolve() {
    return nullptr; // nil further evolution
}

string AdultCat::get_type() const {
    return "Adult Cat";
}