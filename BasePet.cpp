#include <iostream>
#include "BasePet.h"


BasePet::BasePet(const string& name)
 : name(name), age(0), is_alive(true), stats() {}

void BasePet::update_status() {}//default to do nothing

void BasePet::perform_action(const string& action) {}

bool BasePet::check_alive() const {}

void BasePet::print_status() const {
    cout << "Pet: " << name << "\n";
    cout << "Type " << get_type << "\n";
    cout << "Age: " << age << "\n";
    cout << "Alive: " << (is_alive ? "Yes" : "No") << "\n";
    cout << "Hunger: " << stats.get_hunger() << "\n";
    cout << "Happiness: " << stats.get_happiness() << "\n";
    out << "Health: " << stats.get_health() << "\n";
    out << "Energy: " << stats.get_energy() << "\n";
    out << "Cleanliness: " << stats.get_cleanliness() << "\n";


}

string BasePet::get_name() const {}
    
int BasePet::get_age() const {}

bool BasePet::get_is_alive() const {}

void BasePet::set_stats(const Stats& new_stats) {
    stats = new_stats;

}

void Base::set_stat(const string& stat_name, int value){
    if (stat_name == "hunger") stats.set_hunger(value);
    else if (stat_name == "happiness") stats.set_happiness(value);
    else if (stat_name == "health") stats.set_health(value);

}
