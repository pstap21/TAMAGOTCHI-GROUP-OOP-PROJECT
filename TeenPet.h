#ifndef TEENPET_H
#define TEENPET_H
#include "BasePet.h"

class TeenPet : public BasePet {
    public:

    TeenPet (const std::string& name, const Stats& prevStats, int age);
    void update_status() override;
    bool check_evolution() override;
    std::unique_ptr<BasePet> evolve() override;
    std::string get_type() const override;

};

#endif 
