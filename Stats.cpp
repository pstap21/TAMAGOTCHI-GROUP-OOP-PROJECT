#include "Stats.h"
#include <memory>
#include "BasePet.h"

// Constructor
// Constructor
Stats::Stats(int health, int hunger, int energy, int happiness, int cleanliness)
    : health(health), hunger(hunger), energy(energy), happiness(happiness), cleanliness(cleanliness) {}


// Getters
int Stats::get_hunger() const { return hunger; }
int Stats::get_happiness() const { return happiness; }
int Stats::get_health() const { return health; }
int Stats::get_cleanliness() const { return cleanliness; }
int Stats::get_energy() const { return energy; }

//setters
void Stats::set_hunger(int h) { hunger = h; }
void Stats::set_happiness(int h) { happiness = h; }
void Stats::set_health(int h) { health = h; }
void Stats::set_energy(int h) { energy = h; }
void Stats::set_cleanliness(int h) { cleanliness = h; }

// Modifiers
void Stats::change_hunger(int delta) { set_hunger(hunger + delta); }
void Stats::change_happiness(int delta) { set_happiness(happiness + delta); }
void Stats::change_health(int delta) { set_health(health + delta); }
void Stats::change_energy(int delta) { set_energy(energy + delta); }
void Stats::change_cleanliness(int delta) { set_cleanliness(cleanliness + delta); }
