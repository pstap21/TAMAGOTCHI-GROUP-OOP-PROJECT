#include <cassert>
#include <memory>
#include <iostream>
#include "BabyDog.h"
#include "TeenDog.h"

// Helper to create a BabyDog with default stats and name
std::unique_ptr<BabyDog> create_babydog(const std::string& name = "Buddy") {
    return std::make_unique<BabyDog>(name);
}

void test_initial_stats() {
    auto baby = create_babydog();
    Stats s = baby->get_stats();
    assert(s.get_hunger() == 50);
    assert(s.get_happiness() == 90);
    assert(s.get_health() == 90);
    assert(s.get_energy() == 100);
    assert(s.get_cleanliness() == 50);
    std::cout << "Initial stats test passed.\n";
}

void test_perform_action_feed() {
    auto baby = create_babydog();
    Stats before = baby->get_stats();

    baby->perform_action("feed");
    Stats after = baby->get_stats();

    assert(after.get_hunger() == before.get_hunger() + 10);
    assert(after.get_happiness() == before.get_happiness() + 4);
    assert(after.get_energy() == before.get_energy() + 5);
    std::cout << "Perform action 'feed' test passed.\n";
}

void test_perform_action_play() {
    auto baby = create_babydog();
    Stats before = baby->get_stats();

    baby->perform_action("play");
    Stats after = baby->get_stats();

    assert(after.get_happiness() == before.get_happiness() + 8);
    assert(after.get_energy() == before.get_energy() - 10);
    assert(after.get_cleanliness() == before.get_cleanliness() - 10);
    std::cout << "Perform action 'play' test passed.\n";
}

void test_perform_action_clean() {
    auto baby = create_babydog();
    Stats before = baby->get_stats();

    baby->perform_action("clean");
    Stats after = baby->get_stats();

    assert(after.get_cleanliness() == before.get_cleanliness() + 10);
    assert(after.get_hunger() == before.get_hunger() - 2);
    std::cout << "Perform action 'clean' test passed.\n";
}

void test_check_alive() {
    auto baby = create_babydog();

    // Should be alive initially
    assert(baby->check_alive());

    // Set health to zero, not alive
    Stats s = baby->get_stats();
    s.set_health(0);
    baby->set_stats(s);
    assert(!baby->check_alive());

    std::cout << "Check alive test passed.\n";
}

void test_check_evolution() {
    auto baby = create_babydog();

    // Not evolved yet: age < 5
    assert(!baby->check_evolution());

    // Set age to 5 but stats below threshold
    baby->set_age(5);
    Stats s = baby->get_stats();
    s.set_happiness(89);     // just below required 90
    s.set_cleanliness(90);   // meets threshold
    baby->set_stats(s);
    assert(!baby->check_evolution());

    // Set happiness to 90 and cleanliness to 90 and age 5, should evolve
    s.set_happiness(90);
    baby->set_stats(s);
    assert(baby->check_evolution());

    std::cout << "Check evolution test passed.\n";
}

void test_evolve_returns_teendog() {
    auto baby = create_babydog();
    baby->set_age(5);
    Stats s = baby->get_stats();
    s.set_happiness(90);
    s.set_cleanliness(90);
    baby->set_stats(s);

    auto evolved_pet = baby->evolve();
    assert(evolved_pet != nullptr);
    assert(evolved_pet->get_type() == "Teen Dog");

    std::cout << "Evolve test passed.\n";
}

int main() {
    test_initial_stats();
    test_perform_action_feed();
    test_perform_action_play();
    test_perform_action_clean();
    test_check_alive();
    test_check_evolution();
    test_evolve_returns_teendog();

    std::cout << "All BabyDog unit tests passed successfully.\n";
    return 0;
}
