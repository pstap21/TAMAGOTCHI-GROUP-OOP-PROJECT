#ifndef BABYCAT_H
#define BABYCAT_H

#include "Cat.h"
#include "BasePet.h"

using namespace std;

class BabyCat : public Cat {
    
public:

    BabyCat(const string& name);
    void update_status() override;
    void perform_action(const std::string& action) override;
    unique_ptr<BasePet> evolve() override;
    string get_type() const override;
    bool check_evolution() const override;
    bool check_alive() const override;
    


};

#endif