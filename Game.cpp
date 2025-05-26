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

BasePet* Game::show_choice_menu () {
    cout << "------Welcome to the Adoption Centre-------\n";
    cout << "What pet would you like to own?\n" ;
    cout << "Enter 1 for Dog\n";
    cout << "Enter 2 for Cat\n";
    cout << "Enter 3 for Bird\n";

    int choice;
    cin >> choice;

    string name;
    BasePet* new_pet = nullptr;//initilise ptr to nullptr

    //create a switch statement for cleaner code
    switch (choice) {
        case 1:
            cout << "\nCongrats! You have chosen a Dog!\n";
            cout << "What would you like to name your dog?\n";
            cin >> name;
            new_pet = new BabyDog(name);  // Create Dog object dynamically
            break;
    
        case 2:
            cout << "\nCongrats! You have chosen a Cat!\n";
            cout << "What would you like to name your cat?\n";
            cin >> name;
            new_pet = new BabyCat(name);  // Create Cat object dynamically
            break;
    
        case 3:
            cout << "\nCongrats! You have chosen a Bird!\n";
            cout << "What would you like to name your bird?\n";
            cin >> name;
            new_pet = new BabyBird(name);  // Create Bird object dynamically
            break;
    
        default:
            cout << "Invalid choice. Please try again.\n";
            return 0;  // exit function early
    }


    
    cout << "Your " << new_pet->get_type() << " named " << new_pet->get_name() << " has been adopted!\n";
    cout << "Press any key to continue...\n";
    string key;
    cin >> key;
    cout << endl;

    return new_pet;
}

void Game::update(BasePet* pet) {
    pet->update_status();
}

void Game::end_game() {
    cout << "Your pet has died. Game over!" << endl;
}

Game::Game(BasePet* pet) {

    cout << "Welcome! The game has started!" << endl;

    unique_ptr<BasePet> evolvedTeenPet = pet->evolve();

    while (evolvedTeenPet == nullptr) {
        if (pet->check_alive() == true) {
            end_game();
            return;
        }

        cout << "Do you want to feed, clean, or play with your " << pet->get_type() << endl;
        cout << "Enter 1 for feed" << endl;
        cout << "Enter 2 for clean" << endl;
        cout << "Enter 3 for play" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "You have chosen to feed your " << pet->get_type() << " !" << endl;
            pet->perform_action("feed");
            break;
    
        case 2:
            cout << "You have chosen to clean your " << pet->get_type() << " !" << endl;
            pet->perform_action("clean");
            break;
    
        case 3:
            cout << "You have chosen to play with your " << pet->get_type() << " !" << endl;
            pet->perform_action("play");
            break;
    
        default:
            cout << "Invalid choice. Please try again." << endl;
            return;
        }

        update(pet);
        unique_ptr<BasePet> evolvedTeenPet = pet->evolve();
    }

    unique_ptr<BasePet> evolvedAdultPet = evolvedTeenPet->evolve();

    while (evolvedAdultPet == nullptr) {
        if (evolvedTeenPet->check_alive() == true) {
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
            pet->perform_action("feed");
            break;
    
        case 2:
            cout << "You have chosen to clean your " << evolvedTeenPet->get_type() << " !" << endl;
            pet->perform_action("clean");
            break;
    
        case 3:
            cout << "You have chosen to play with your " << evolvedTeenPet->get_type() << " !" << endl;
            pet->perform_action("play");
            break;
    
        default:
            cout << "Invalid choice. Please try again." << endl;
            return;
        }

        evolvedTeenPet->update_status();
        unique_ptr<BasePet> evolvedAdultPet = evolvedTeenPet->evolve();
    }


     while (evolvedAdultPet->check_alive() == true) {

        cout << "Do you want to feed, clean, or play with your " << evolvedAdultPet->get_type() << endl;
        cout << "Enter 1 for feed" << endl;
        cout << "Enter 2 for clean" << endl;
        cout << "Enter 3 for play" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "You have chosen to feed your " << evolvedAdultPet->get_type() << " !" << endl;
            pet->perform_action("feed");
            break;
    
        case 2:
            cout << "You have chosen to clean your " << evolvedAdultPet->get_type() << " !" << endl;
            pet->perform_action("clean");
            break;
    
        case 3:
            cout << "You have chosen to play with your " << evolvedAdultPet->get_type() << " !" << endl;
            pet->perform_action("play");
            break;
    
        default:
            cout << "Invalid choice. Please try again." << endl;
            return;
        }

        evolvedAdultPet->update_status();
    }

    end_game();

   


    }

 Game::~Game() {
        //no destuctor needed

    }