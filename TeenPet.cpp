#include "TeenPet.h"

TeenPet::TeenPet(const string& name, const Stats& prevStats, int age) : BasePet(name) {}

void TeenPet::update_status() {}

bool TeenPet::check_evolution() const {}

unique_ptr<BasePet> TeenPet::evolve() {}

string TeenPet::get_type() const {}