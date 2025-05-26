#ifndef ADULTDOG_H
#define ADULTDOG_H

#include "Dog.h"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class AdultDog : public Dog {

public:

    AdultDog(const string& name);

    void update_status() override;
    void perform_action(const std::string& action) override;
    bool check_alive() const override;
    bool check_evolution() const override;
    unique_ptr<BasePet> evolve() override;
    string get_type() const override;
};

#endif
