#ifndef BABYPET_H
#define BABYPET_H

#include "BasePet.h"

class BabyPet : public BasePet {
    public:

    BabyPet(const std::string& name);
    void update_status() override;
    bool check_evolution() override;
    std::unique_ptr<BasePet> evolve() override;
    std::string get_type() const override;

};

#endif 
