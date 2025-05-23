#ifndef STATS_H
#define STATS_H

#include <string>

using namespace std;

class Stats {

private:
    int health;
    int hunger;
    int energy;
    int happiness;
    int cleanliness;
    
public:
    Stats(int hunger = 50, int happiness = 50, int health = 50,
          int cleanliness = 50, int energy = 50);

    int get_hunger() const {return hunger;}
    int get_happiness() const {return happiness;}
    int get_health() const {return health;}
    int get_energy() const {return energy;}
    int get_cleanliness() const {return cleanliness;}

    void set_hunger(int h) {hunger = h;}
    void set_happiness(int h) { happiness = h;}
    void set_health(int h) {health = h;}
    void set_energy(int h) {energy = h;}
    void set_cleanliness(int h) {cleanliness = h;}

    //modifiers
    void change_hunger(int delta);
    void change_happiness(int delta);
    void change_energy(int delta);
    void change_cleanliness(int delta);
    void change_health(int delta);



};

#endif
