#ifndef HAT_H
#define CAT_H

#include "BasePet.h"
#include <string>
#include <iostream>

class Cat : public BasePet {
    public:
    Cat (const std::string& name);

    void update_status() override;
    void perform_action(const std::string& action) override;
    bool check_evolution() const override;
    bool check_alive() const override;
    std::unique_ptr<BasePet> evolve() override;
    std::string get_type() const override;


};

#endif