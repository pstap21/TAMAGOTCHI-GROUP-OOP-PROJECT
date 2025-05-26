#ifndef DOG_H
#define DOG_H
#include <memory>
#include "BasePet.h"
#include <string>
#include <iostream>

using namespace std;

class Dog : public BasePet {
    
public:
    Dog(const string& name, int age);

    void update_status() override;
    void perform_action(const string& action) override;
    bool check_evolution() const override;
    bool check_alive() const override;
    unique_ptr<BasePet> evolve() override;
    string get_type() const override;


};

#endif