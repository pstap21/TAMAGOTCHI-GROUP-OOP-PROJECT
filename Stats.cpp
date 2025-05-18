#include "Stats.h"

Stats::Stats() : health(0), hunger(0), happiness(0), cleanliness(0), energy(0) {}

void Stats::decay() {
    double rate = 1.2;
}

void Stats::change_state(const string& stat, int value) {}

void Stats::display() const {}

int Stats::get_stat(const string& stat) const {}