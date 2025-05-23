#include "Stats.h"
#include <memory>
#include "BasePet.h"

// Constructor
// Constructor
Stats::Stats(int hunger, int happiness, int health, int cleanliness, int energy)
    : hunger(hunger), happiness(happiness), health(health),
      cleanliness(cleanliness), energy(energy) {}


// Getters
int Stats::get_hunger() const { return hunger; }
int Stats::get_happiness() const { return happiness; }
int Stats::get_health() const { return health; }

// Setters
void Stats::set_hunger(int value) {
    hunger = (value < 0) ? 0 : (value > 100 ? 100 : value);
}

void Stats::set_happiness(int value) {
    happiness = (value < 0) ? 0 : (value > 100 ? 100 : value);
}

void Stats::set_health(int value) {
    health = (value < 0) ? 0 : (value > 100 ? 100 : value);
}

// Modifiers
void Stats::change_hunger(int delta) {
    set_hunger(hunger + delta);
}

void Stats::change_happiness(int delta) {
    set_happiness(happiness + delta);
}

void Stats::change_health(int delta) {
    set_health(health + delta);
}
