#include <iostream>
#include "BasePet.h"


BasePet::BasePet(const string& name) : name(name), age(0), is_alive(true) {}

void BasePet::update_status() {}

void BasePet::perform_action(const string& action) {}

bool BasePet::check_alive() const {}

void BasePet::print_status() const {}

string BasePet::get_name() const {}
    
int BasePet::get_age() const {}

bool BasePet::get_is_alive() const {}

Stats BasePet::get_stats() const {}
