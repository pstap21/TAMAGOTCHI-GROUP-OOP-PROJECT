#ifndef BABYDOG_H
#define BABYDOG_H

#include "Dog.h"
#include "BasePet.h"

class BabyDog : public Dog {
    
public:

    BabyDog(const std::string& name);
    void update_status() override;
    void perform_action(const std::string& action) override;
    std::unique_ptr<BasePet> evolve() override;
    std::string get_type() const override;
    bool check_evolution() const override;
    bool check_alive() const override;
    


};

#endif