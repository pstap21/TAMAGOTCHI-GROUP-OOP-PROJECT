#include <iostream>
#include <string>
#include "BasePet.h"
#include "Stats.h"

using namespace std;

void test_constructor_and_getters() {
    BasePet pet("Fido", 3);
    if (pet.get_name() == "Fido" && pet.get_age() == 3 && pet.get_is_alive() == true) {
        cout << "test_constructor_and_getters passed\n";
    } else {
        cout << "test_constructor_and_getters FAILED\n";
    }
}

void test_set_and_get_stats() {
    BasePet pet("Fido", 2);
    Stats s;
    s.set_hunger(20);
    s.set_happiness(50);
    pet.set_stats(s);
    Stats s2 = pet.get_stats();

    if (s2.get_hunger() == 20 && s2.get_happiness() == 50) {
        cout << "test_set_and_get_stats passed\n";
    } else {
        cout << "test_set_and_get_stats FAILED\n";
    }
}

void test_set_stats_string_int() {
    BasePet pet("Buddy", 1);
    pet.set_stats("hunger", 40);
    pet.set_stats("happiness", 80);
    pet.set_stats("health", 70);
    pet.set_stats("energy", 60);
    pet.set_stats("cleanliness", 90);

    Stats s = pet.get_stats();
    if (s.get_hunger() == 40 && s.get_happiness() == 80 &&
        s.get_health() == 70 && s.get_energy() == 60 &&
        s.get_cleanliness() == 90) {
        cout << "test_set_stats_string_int passed\n";
    } else {
        cout << "test_set_stats_string_int FAILED\n";
    }
}

void test_check_alive() {
    BasePet pet("Fido", 2);
    if (pet.check_alive()) {
        cout << "test_check_alive passed\n";
    } else {
        cout << "test_check_alive FAILED\n";
    }
}

// For print_status we can just call it (manual visual check)
void test_print_status() {
    BasePet pet("Fido", 4);
    cout << "test_print_status output:\n";
    pet.print_status();
    cout << "(Check output manually)\n";
}

int main() {
    test_constructor_and_getters();
    test_set_and_get_stats();
    test_set_stats_string_int();
    test_check_alive();
    test_print_status();

    return 0;
}
