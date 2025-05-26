#ifndef BABYDOG_H
#define BABYDOG_H

#include "Dog.h"
#include "BasePet.h"

using namespace std;

class BabyDog : public Dog {
    
public:

    BabyDog(const string& name);
    void update_status() override;
    void perform_action(const string& action) override;
    std::unique_ptr<BasePet> evolve() override;
    std::string get_type() const override;
    bool check_evolution() const override;
    bool check_alive() const override;
    


};

#endif