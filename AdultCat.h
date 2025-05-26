#ifndef ADULTCAT_H
#define ADULTCAT_H

#include "Cat.h"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class AdultCat : public Cat {

public:

    AdultCat(const string& name);

    void update_status() override;
    void perform_action(const string& action) override;
    bool check_alive() const override;
    bool check_evolution() const override;
    unique_ptr<BasePet> evolve() override;
    string get_type() const override;
};

#endif
