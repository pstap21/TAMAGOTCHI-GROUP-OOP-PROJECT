#ifndef CAT_H
#define CAT_H
#include <memory>
#include "BasePet.h"
#include <string>
#include <iostream>

using namespace std;

class Cat : public BasePet {

public:
    Cat(const string& name, int age);

    void update_status() override;
    void perform_action(const string& action) override;
    virtual bool check_evolution() const = 0;
    bool check_alive() const override;
    unique_ptr<BasePet> evolve() override;
    string get_type() const override;


};

#endif