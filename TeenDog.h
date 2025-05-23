#ifndef TEENDOG_H
#define TEENGOD_H

#include "BasePet.h"
#include <memory>

class TeenDog : public BasePet {
    public:

    TeenDog(const std::string& name);
    void update_status() override;
    void perform_action(const std::string& action) override;
    std::unique_ptr<BasePet> evolve() override;
    std::string get_type() const override;
    bool check_evolution() const override;


};

#endif