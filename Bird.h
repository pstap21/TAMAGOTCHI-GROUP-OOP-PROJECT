#ifndef BIRD_H
#define BIRD_H

#include <memory>
#include "BasePet.h"
#include <string>

// Bird class inherits from BasePet, meaning it is a specialized type of BasePet
class Bird : public BasePet {

public:
    // Constructor: initializes a Bird object with a given name
    // It will also set default stats for a Bird (e.g., happiness, hunger)
    Bird(const string& name, int age);

    // Override BasePet virtual functions to provide Bird-specific behavior:

    // update_status will update hunger, happiness, etc., as time passes
    void update_status() override;

    // perform_action will change the bird's state based on user input (feeding, playing, etc.)
    void perform_action(const std::string& action) override;

    // check_alive will return true if the bird is still alive (not starving or unhealthy)
    bool check_alive() const override;

    // check_evolution will return true if the bird meets the criteria to evolve
    virtual bool check_evolution() const = 0;

    // evolve will return a pointer to a new evolved BasePet object (or nullptr if no evolution)
    std::unique_ptr<BasePet> evolve() override;

    // get_type returns the type of pet as a string, e.g., "Bird"
    std::string get_type() const override;

};

#endif