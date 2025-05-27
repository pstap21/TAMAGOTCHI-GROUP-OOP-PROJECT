

#include "Game.h"
#include "BabyDog.h"   
#include "BabyCat.h"
#include "BabyBird.h"
#include "Stats.h"
#include "BasePet.h"
#include "Cat.h"
#include "Dog.h"
#include "Bird.h"
#include <iostream>
#include <memory>

using namespace std;

Game::Game(std::unique_ptr<BasePet> pet) 
    : current_pet(std::move(pet)), running(true) {}

Game::~Game() {}

void Game::start() {
    if(!current_pet) {
        cout << "No pet has been chosen, exiting the game.\n";
        return;
    }

    cout << "Welcome! The game has started!" << endl;

    while (running && current_pet->check_alive()) {
        show_main_menu();

        // Update pet status explicitly is optional here since show_main_menu does it,
        // but keeping it for safety.
        update(current_pet.get());

        // Attempt to evolve the pet after each action
        auto evolvedPet = current_pet->evolve();

        if (evolvedPet) {
            cout << current_pet->get_name() << " evolved into a " << evolvedPet->get_type() << "!" << endl;
            current_pet = std::move(evolvedPet);
            current_pet->update_status();
            current_pet->print_status();
        }
    }

    end_game();
}

unique_ptr<BasePet> Game::show_choice_menu() {
    cout << "------Welcome to the Adoption Centre-------\n";
    cout << "What pet would you like to own?\n";
    cout << "Enter 1 for Dog\n";
    cout << "Enter 2 for Cat\n";
    cout << "Enter 3 for Bird\n";

    int choice;
    cin >> choice;

    string name;

    switch (choice) {
        case 1:
            cout << "\nCongrats! You have chosen a Dog!\n";
            cout << "What would you like to name your dog?\n";
            cin >> name;
            return make_unique<BabyDog>(name);

        case 2:
            cout << "\nCongrats! You have chosen a Cat!\n";
            cout << "What would you like to name your cat?\n";
            cin >> name;
            return make_unique<BabyCat>(name);

        case 3:
            cout << "\nCongrats! You have chosen a Bird!\n";
            cout << "What would you like to name your bird?\n";
            cin >> name;
            return make_unique<BabyBird>(name);

        default:
            cout << "Invalid choice. Please try again.\n";
            return nullptr;
    }
}

void Game::update(BasePet* pet) {
    pet->update_status();
}

void Game::end_game() {
    cout << "Your pet has died. Game over!" << endl;
}

BasePet* Game::show_main_menu() {
    cout << "Do you want to feed, clean, or play with your " << current_pet->get_type() << "?" << endl;
    cout << "Enter 1 for feed" << endl;
    cout << "Enter 2 for clean" << endl;
    cout << "Enter 3 for play" << endl;

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "You have chosen to feed your " << current_pet->get_type() << "!" << endl;
            current_pet->perform_action("feed");
            current_pet->update_status();
            current_pet->print_status();
            break;

        case 2:
            cout << "You have chosen to clean your " << current_pet->get_type() << "!" << endl;
            current_pet->perform_action("clean");
            current_pet->update_status();
            current_pet->print_status();
            break;

        case 3:
            cout << "You have chosen to play with your " << current_pet->get_type() << "!" << endl;
            current_pet->perform_action("play");
            current_pet->update_status();
            current_pet->print_status();
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            // Return nullptr to indicate invalid choice, but the loop in start() will repeat
            return nullptr;
    }
    return current_pet.get();
}
