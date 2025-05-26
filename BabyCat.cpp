#include "TeenCat.h"
#include "BabyCat.h"
#include "BasePet.h"
#include "Stats.h"
#include <iostream>
#include <memory>

using namespace std;

BabyCat::BabyCat (const string&name) : Cat(name, 0) {
    //evolution stats
    Stats baby_stats;
    baby_stats.set_hunger(50);
    baby_stats.set_happiness(90);
    baby_stats.set_health(90);
    baby_stats.set_energy(100);
    baby_stats.set_cleanliness(50);
    set_stats(baby_stats);


}
void BabyCat::update_status() {
    Stats s = get_stats();
    s.change_hunger(5);
    s.change_happiness(-4);
    s.change_energy(-5);
    s.change_cleanliness(-5);
    s.change_health(-2);
    set_stats(s);
    age++;
}

void BabyCat::perform_action(const string&action) {
    Stats s = get_stats();

    if(action == "feed") {
        s.change_hunger(-10);
        s.change_happiness(4);
        s.change_energy(5);
        cout << "You fed" << get_name() << " " << ". Its growing big and strong!\n";
    } else if (action == "play") {
        s.change_happiness(8);
        s.change_energy(-10);
        cout << "You played with" << get_name() << " " << ". It ran around with lots of energy!\n";
    } else if(action == "clean") {
        s.change_cleanliness(10);
        cout << "You washed" << get_name() << " " << ". They are now sparkling clean!!\n";
    } else  {
        "Action not supported, try again.\n";
    }
    set_stats(s);

}

bool BabyCat::check_alive() const {
    Stats s = get_stats();
    return s.get_hunger() < 100 && s.get_health() > 0;

}

bool BabyCat::check_evolution() const {
    return get_age() >= 5 && get_stats().get_happiness() >= 90;
}

unique_ptr<BasePet> BabyCat::evolve() {
    if(check_evolution()) {
        cout << get_name() << "is evolving into an adult cat!!\n";
        return make_unique<TeenCat>(get_name());
    }
    return nullptr;
}

string BabyCat::get_type() const {
    return "Baby Cat";
}