#ifndef TEENDOG_H
#define TEENDOG_H

#include "Dog.h"

using namespace std;

class TeenDog : public Dog {
    
public:

    TeenDog(const string& name);
    void update_status() override;
    void perform_action(const std::string& action) override;
    unique_ptr<BasePet> evolve() override;
    string get_type() const override;
    bool check_evolution() const override;
    bool check_alive() const override;


};

#endif
