#ifndef ADULTCAT_H
#define ADULTCAT_H

#include "BasePet.h"
#include<iostream>
#include <string>
#include <memory>

class AdultCat : public BasePet {
    public:

    AdultCat(const std::string& name);

    void update_status() override;
    void perform_action(const std::string& action) override;
    bool check_alive() const override;
    bool check_evolution() const override;
    std::unique_ptr<BasePet> evolve() override;
    std::string get_type() const override;
};

#endif
