#include "TeenCat.h"
#include "AdultCat.h"
#include "BasePet.h"
#include "Stats.h"
#include "Cat.h"
#include <iostream>
#include <memory>

using namespace std;

TeenCat::TeenCat (const string&name) : Cat(name, 5) {
    //evolution stats
    Stats teen_stats;
    teen_stats.set_hunger(60);
    teen_stats.set_happiness(80);
    teen_stats.set_health(100);
    teen_stats.set_energy(90);
    teen_stats.set_cleanliness(70);
    set_stats(teen_stats);
}

void TeenCat::update_status() {
    Stats s = get_stats();
    s.change_hunger(6);
    s.change_happiness(-3);
    s.change_energy(-4);
    s.change_cleanliness(-4);
    s.change_health(-1);
    set_stats(s);
    age++;
}


void TeenCat::perform_action(const string&action) {
    Stats s = get_stats();

    if(action == "feed") {
        s.change_hunger(-8);
        s.change_happiness(4);
        s.change_energy(3);
        cout << "You fed" << get_name() << " " << ". Its growing big and strong!\n";
    } else if (action == "play") {
        s.change_happiness(4);
        s.change_energy(-8);
        cout << "You played with" <<get_name() << " " << ". It ran around with lots of energy!\n";
    } else if(action == "clean") {
        s.change_cleanliness(10);
        cout << "You washed" << get_name() << " " << ". They are now sparkling clean!!\n";
    } else  {
        cout << "Action not supported, try again.\n";
    }
    set_stats(s);

    }
    bool TeenCat::check_evolution() const { 
    return get_age() >= 15 && get_stats().get_happiness() >= 90;
}

bool TeenCat::check_alive() const {
    Stats s = get_stats();
    return s.get_hunger() < 100 && s.get_health() > 0;
}

unique_ptr<BasePet> TeenCat::evolve() {
    if(check_evolution()) {
        cout << get_name() << "is evolving into an adult cat!!\n";
        return make_unique<AdultCat>(get_name());
    }
    return nullptr;
}

string TeenCat::get_type() const {
    return "Teen Cat";
}