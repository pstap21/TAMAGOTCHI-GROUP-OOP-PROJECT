#ifndef DOG_H
#define DOG_H

#include "BasePet.h"
#include <string>

// Dog class inherits from BasePet, meaning it is a specialized type of BasePet
class Dog : public BasePet {
public:
    // Constructor: initializes a Dog object with a given name
    // It will also set default stats for a Dog (e.g., happiness, hunger)
    Dog(const std::string& name);

    // Override BasePet virtual functions to provide Dog-specific behavior:

    // update_status will update hunger, happiness, etc., as time passes
    void update_status() override;

    // perform_action will change the dog's state based on user input (feeding, playing, etc.)
    void perform_action(const std::string& action) override;

    // check_alive will return true if the dog is still alive (not starving or unhealthy)
    bool check_alive() const override;

    // check_evolution will return true if the dog meets the criteria to evolve
    bool check_evolution() const override;

    // evolve will return a pointer to a new evolved BasePet object (or nullptr if no evolution)
    BasePet* evolve() override;

    // get_type returns the type of pet as a string, e.g., "Dog"
    std::string get_type() const override;
};

#endif