#ifndef TEENCAT_H
#define TEENCAT_H

#include "Cat.h"

class TeenCat : public Cat {
    public:

    TeenCat(const string& name);
    void update_status() override;
    void perform_action(const string& action) override;
    unique_ptr<BasePet> evolve() override;
    string get_type() const override;
    bool check_evolution() const override;
    bool check_alive() const override;
    


};

#endif