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
    Stats(int health = 50, int hunger = 50, int energy = 50,
          int happiness = 50, int cleanliness = 50);

    int get_hunger() const ;
    int get_happiness() const ;
    int get_health() const ;
    int get_energy() const;
    int get_cleanliness() const;

    void set_hunger(int h) ;
    void set_happiness(int h); 
    void set_health(int h) ;
    void set_energy(int h) ;
    void set_cleanliness(int h) ;
    //modifiers
    void change_hunger(int delta);
    void change_happiness(int delta);
    void change_energy(int delta);
    void change_cleanliness(int delta);
    void change_health(int delta);



};

#endif
