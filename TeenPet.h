#ifndef TEENPET_H
#define TEENPET_H

#include "BasePet.h"

class TeenPet : public BasePet {
    
public:
    TeenPet (const string& name, const Stats& prevStats, int age);
    void update_status() override;
    bool check_evolution() const override;
    unique_ptr<BasePet> evolve() override;
    string get_type() const override;

};

#endif 
