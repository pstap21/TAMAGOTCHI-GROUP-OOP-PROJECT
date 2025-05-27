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
: current_pet(std::move(pet)), running(true)  {}

Game::~Game()  {}

void Game::start() {
    if(!current_pet) {
        std::cout << "No pet has been chosen, exiting the game.\n";
        return;
    }

    std::cout << "Welcome! The game has started!" << endl;

while (running && current_pet->check_alive()){
    show_main_menu();
    update(current_pet.get());

    unique_ptr<BasePet> evolvedTeenPet = current_pet->evolve();
    update(current_pet.get());
    // auto evolved_pet = current_pet->evolve();
    // if (evolved_pet) {
    //     current_pet = std::move(evolved_pet);

    // }
    //end_game();
    
    while (evolvedTeenPet == nullptr) {
        if (!current_pet->check_alive()) {
            end_game();
            return;
        }

        show_main_menu();
        update(current_pet.get());
        evolvedTeenPet = current_pet->evolve();
    }

    unique_ptr<BasePet> evolvedAdultPet = evolvedTeenPet->evolve();
    

    while (evolvedAdultPet == nullptr) {
        if (!evolvedTeenPet->check_alive()) {
            end_game();
            return;
        }

        cout << "Do you want to feed, clean, or play with your " << evolvedTeenPet->get_type() << endl;
        cout << "Enter 1 for feed" << endl;
        cout << "Enter 2 for clean" << endl;
        cout << "Enter 3 for play" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "You have chosen to feed your " << evolvedTeenPet->get_type() << " !" << endl;
            current_pet->perform_action("feed");
            evolvedTeenPet->print_status();
            break;
    
        case 2:
            cout << "You have chosen to clean your " << evolvedTeenPet->get_type() << " !" << endl;
            current_pet->perform_action("clean");
            evolvedTeenPet->print_status();
            break;
    
        case 3:
            cout << "You have chosen to play with your " << evolvedTeenPet->get_type() << " !" << endl;
            current_pet->perform_action("play");
            evolvedTeenPet->print_status();
            break;
    
        default:
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        evolvedTeenPet->update_status();
        evolvedAdultPet = evolvedTeenPet->evolve();

        
        unique_ptr<BasePet> evolvedAdultPet = evolvedTeenPet->evolve();
    }


     while (evolvedAdultPet->check_alive()) {

        cout << "Do you want to feed, clean, or play with your " << evolvedAdultPet->get_type() << endl;
        cout << "Enter 1 for feed" << endl;
        cout << "Enter 2 for clean" << endl;
        cout << "Enter 3 for play" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "You have chosen to feed your " << evolvedAdultPet->get_type() << " !" << endl;
            current_pet->perform_action("feed");
            evolvedAdultPet->print_status();
            break;
    
        case 2:
            cout << "You have chosen to clean your " << evolvedAdultPet->get_type() << " !" << endl;
            current_pet->perform_action("clean");
            evolvedAdultPet->print_status();
            break;
    
        case 3:
            cout << "You have chosen to play with your " << evolvedAdultPet->get_type() << " !" << endl;
            current_pet->perform_action("play");
            evolvedAdultPet->print_status();
            break;
    
        default:
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        evolvedAdultPet->update_status();
    }
}
end_game();

}

BasePet* new_pet = nullptr;//initilise ptr to nullptr

std::unique_ptr<BasePet> Game::show_choice_menu() {
    cout << "------Welcome to the Adoption Centre-------\n";
    cout << "What pet would you like to own?\n" ;
    cout << "Enter 1 for Dog\n";
    cout << "Enter 2 for Cat\n";
    cout << "Enter 3 for Bird\n";

    int choice;
    std::cin >> choice;

    std::string name;

    //create a switch statement for cleaner code
    switch (choice) {
        case 1:
            std::cout << "\nCongrats! You have chosen a Dog!\n";
            std::cout << "What would you like to name your dog?\n";
            std::cin >> name;
            return std::make_unique<BabyDog>(name); // Create Dog object dynamically
            //break;
    
        case 2:
            std::cout << "\nCongrats! You have chosen a Cat!\n";
            std::cout << "What would you like to name your cat?\n";
            std::cin >> name;
            return std::make_unique<BabyCat>(name);  // Create Cat object dynamically
            //break;
    
        case 3:
            std::cout << "\nCongrats! You have chosen a Bird!\n";
            std::cout << "What would you like to name your bird?\n";
            std::cin >> name;
            return std::make_unique<BabyBird>(name); // Create Bird object dynamically
            //break;
    
        default:
            std::cout << "Invalid choice. Please try again.\n";
            return nullptr;  // exit function early
    
    cout << "Your " << new_pet->get_type() << " named " << new_pet->get_name() << " has been adopted!\n";
    cout << "Press enter to continue...\n";
    std::cin.ignore();
    cin.get();
    cout << endl;
    
    }
    
}


void Game::update(BasePet* pet) {
    pet->update_status();
}


void Game::end_game() {
    cout << "Your pet has died. Game over!" << endl;
}

BasePet* Game::show_main_menu () {
        cout << "Do you want to feed, clean, or play with your " << current_pet->get_type() << endl;
        cout << "Enter 1 for feed" << endl;
        cout << "Enter 2 for clean" << endl;
        cout << "Enter 3 for play" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "You have chosen to feed your " << current_pet->get_type() << " !" << endl;
            current_pet->perform_action("feed");
            break;
    
        case 2:
            cout << "You have chosen to clean your " << current_pet->get_type() << " !" << endl;
            current_pet->perform_action("clean");
            break;
    
        case 3:
            cout << "You have chosen to play with your " << current_pet->get_type() << " !" << endl;
            current_pet->perform_action("play");
            break;
    
        default:
            cout << "Invalid choice. Please try again." << endl;
            return nullptr;
        }
        return current_pet.get();

        }

    // while(running) {
    //     if (!current_pet->check_alive()){
    //         end_game();
    //         return;
    //     }
    // }