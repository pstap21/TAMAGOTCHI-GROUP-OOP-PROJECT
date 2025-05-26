#ifndef TEENBIRD_H
#define TEENBIRD_H

#include "Bird.h"

using namespace std;

class TeenBird : public Bird {
    public:

    TeenBird(const string& name);
    void update_status() override;
    void perform_action(const string& action) override;
    std::unique_ptr<BasePet> evolve() override;
    std::string get_type() const override;
    bool check_evolution() const override;
    bool check_alive() const override;
    


};

#endif