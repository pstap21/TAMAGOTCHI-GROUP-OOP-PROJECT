#ifndef BASEPET_H
#define BASEPET_H

#include "Stats.h"

using namespace std;

class BasePet {
    private:
    string name;
    int age;
    bool is_alive;
    Stats stats;

    public:
    BasePet(const string& name);//constructor
    virtual ~BasePet() = default;//destructor


    virtual void update_status();
    void print_status() const;

    virtual bool check_evolution() const = 0;
    virtual bool check_alive() const;
    virtual void perform_action(const string& action);
    virtual unique_ptr<BasePet> evolve() = 0;
    virtual string get_type() const = 0;

    string get_name() const;
    int get_age() const;
    bool get_is_alive() const;
    Stats get_stats() const;



};

#endif

