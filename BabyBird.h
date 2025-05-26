#ifndef BABYBIRD_H
#define BABYBIRD_H

#include "Bird.h"
#include "BasePet.h"

using namespace std;

class BabyBird : public Bird {

public:

    BabyBird(const string& name);
    void update_status() override;
    void perform_action(const string& action) override;
    unique_ptr<BasePet> evolve() override;
    string get_type() const override;
    bool check_evolution() const override;
    bool check_alive() const override;
    


};

#endif