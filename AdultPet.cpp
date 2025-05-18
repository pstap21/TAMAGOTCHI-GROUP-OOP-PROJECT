#include "AdultPet.h"

AdultPet::AdultPet(const string& name, const Stats& prevStats, int age) : BasePet(name) {}

void AdultPet::update_status() {}

bool AdultPet::check_evolution() const {}

unique_ptr<BasePet> AdultPet::evolve() {}

string AdultPet::get_type() const {}