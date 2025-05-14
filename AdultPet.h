#ifndef ADULTPET_H
#define ADULTPET_H
#include "BasePet.h"

class AdultPet : public BasePet {

    public:
    AdultPet ( const std::string& name, const Stats& prevStats, int age);
    void update_status() override;
    bool check_evolution() const override;
    std::unique_ptr<BasePet> evolve() override;
    std::string get_type() const override;

};

#endif
