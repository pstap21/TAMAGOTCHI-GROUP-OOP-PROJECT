#include <iostream>
#include "BasePet.h"
#include <memory>

#include <string>

using namespace std;


BasePet::BasePet(const string& name, int age)
 : name(name), age(age), is_alive(true), stats() {}

void BasePet::update_status() {}//default to do nothing

void BasePet::perform_action(const string &action) {
    (void)action;
    //implementation does nothing
}

bool BasePet::check_alive() const {
    return is_alive;
}

void BasePet::print_status() const {
    cout << "Pet: " << name << "\n";
    cout << "Type " << get_type() << "\n";
    cout << "Age: " << age << "\n";
    cout << "Alive: " << (is_alive ? "Yes" : "No") << "\n";
    cout << "Hunger: " << stats.get_hunger() << "\n";
    cout << "Happiness: " << stats.get_happiness() << "\n";
    cout << "Health: " << stats.get_health() << "\n";
    cout << "Energy: " << stats.get_energy() << "\n";
    cout << "Cleanliness: " << stats.get_cleanliness() << "\n";


}

string BasePet::get_name() const {
    return name;
}
    
int BasePet::get_age() const {
    return age;
}

bool BasePet::get_is_alive() const {
    return is_alive;
}

Stats BasePet::get_stats() const {
    return stats;
    
}
void BasePet::set_stats(const Stats& new_stats) {
stats = new_stats;
}


void BasePet::set_stats(const string& stat_name, int value){
    if (stat_name == "hunger") stats.set_hunger(value);
    else if (stat_name == "happiness") stats.set_happiness(value);
    else if (stat_name == "health") stats.set_health(value);
    else if (stat_name == "energy") stats.set_energy(value);
    else if (stat_name == "cleanliness") stats.set_cleanliness(value);

};


