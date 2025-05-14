#ifndef STATS_H
#define STATS_H

using namespace std;

class Stats {
    private:
    int hunger;
    int happiness;
    int cleanliness;
    int health;
    int energy;

    public:
    Stats();

    void decay(double rate = 1.2);
    void change_state( const std::string& stat, int value);
    void display() const;
    int get_stat(const std::string& stat) const;


};

#endif