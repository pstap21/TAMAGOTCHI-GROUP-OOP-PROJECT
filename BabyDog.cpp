#include "TeenDog.h"
#include "BabyDog.h"
#include "BasePet.h"
#include "Stats.h"
#include <iostream>
#include <memory>

using namespace std;

BabyDog::BabyDog (const string&name) : Dog(name, 0) {
    //evolution stats
    Stats baby_stats;
    baby_stats.set_hunger(50);
    baby_stats.set_happiness(90);
    baby_stats.set_health(90);
    baby_stats.set_energy(100);
    baby_stats.set_cleanliness(50);
    set_stats(baby_stats);


}
void BabyDog::update_status() {
    Stats s = get_stats();
    s.change_hunger(0);
    s.change_happiness(0);
    s.change_energy(0);
    s.change_cleanliness(0);
    s.change_health(0);
    set_stats(s);
    age++;
}

void BabyDog::perform_action(const string&action) {
    Stats s = get_stats();

    if(action == "feed") {
        s.change_hunger(10);
        s.change_happiness(4);
        s.change_energy(5);
        cout << "You fed" << get_name() << " " << ". Its growing big and strong!\n";
    } else if (action == "play") {
        s.change_happiness(8);
        s.change_energy(10);
        s.change_cleanliness(-10);
        cout << "You played with" << get_name() << " " << ". It ran around with lots of energy!\n";
    } else if(action == "clean") {
        s.change_cleanliness(10);
        s.change_hunger(-2);
        cout << "You washed" << get_name() << " " << ". They are now sparkling clean!!\n";
    } else  {
        cout << "Action not supported, try again.\n";
    }
    set_stats(s);

}

bool BabyDog::check_alive() const {
    Stats s = get_stats();
    return s.get_hunger() <= 100 && s.get_health() > 0;

}

bool BabyDog::check_evolution() const {
    return  get_stats().get_happiness() >= 90 && get_stats().get_cleanliness() >= 90;
}

unique_ptr<BasePet> BabyDog::evolve() {
    if(check_evolution()) {
        cout << get_name() << "is evolving into an teen Dog!!\n";
        return std::make_unique<TeenDog>(get_name());
    }
    return nullptr;
}

string BabyDog::get_type() const {
    return "Baby Dog";

}