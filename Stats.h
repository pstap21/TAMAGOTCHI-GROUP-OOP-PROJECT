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
    Stats();

    void decay();
    void change_state(const string& stat, int value);
    void display() const;
    int get_stat(const string& stat) const;


};

#endif