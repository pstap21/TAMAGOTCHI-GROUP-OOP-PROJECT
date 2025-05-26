#ifndef ADULTBIRD_H
#define ADULTBIRD_H

#include "Bird.h"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class AdultBird : public Bird {

public:

    AdultBird(const string& name);

    void update_status() override;
    void perform_action(const string& action) override;
    bool check_alive() const override;
    bool check_evolution() const override;
    unique_ptr<BasePet> evolve() override;
    string get_type() const override;
};

#endif
