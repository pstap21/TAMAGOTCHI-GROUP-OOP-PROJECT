#include "Game.h"
#include "Game.h"
#include "Dog.h"    // Include in cpp file
#include "Cat.h"
#include "Bird.h"
#include <iostream>


using namespace std;

    void show_main_menu() {
        std::cout << " -----------------------\n" ;
        std::cout << "Welcome to the Adoption Centre\n" ;
        std::cout << " -----------------------\n" ;
        std::cout << "1) Start Game\n";
        std::cout << "3) Exit\n" ;
        std::cout << "Please choice an option:  \n";


    }
//if 1) is chosen, a new game is started 
    void show_choice_menu () {
        std::cout << "------Welcome to the Adoption Centre-------\n";
        std::cout << "What pet would you like to own?\n" ;
        std::cout << "Enter 1 for Dog\n";
        std::cout << "Enter 2 for Cat\n";
        std::cout << "Enter 3 for Bird\n";

        int choice;
        cin >> choice;

        string name;
        BasePet* new_pet = nullptr;//initilise ptr to nullptr

        //create a switch statement for cleaner code
        switch (choice) {
            case 1:
                cout << "\nCongrats! You have chosen a Dog!\n";
                cout << "Dogs start with 100 happiness and 50 hunger.\n";
                cout << "What would you like to name your dog?\n";
                cin >> name;
                new_pet = new Dog(name);  // Create Dog object dynamically
                break;
    
            case 2:
                cout << "\nCongrats! You have chosen a Cat!\n";
                cout << "Cats start with 80 happiness and 40 hunger.\n";
                cout << "What would you like to name your cat?\n";
                cin >> name;
                new_pet = new Cat(name);  // Create Cat object dynamically
                break;
    
            case 3:
                cout << "\nCongrats! You have chosen a Bird!\n";
                cout << "Birds start with 90 happiness and 30 hunger.\n";
                cout << "What would you like to name your bird?\n";
                cin >> name;
                new_pet = new Bird(name);  // Create Bird object dynamically
                break;
    
            default:
                cout << "Invalid choice. Please try again.\n";
                return;  // exit function early
        }

        //create a new pet and safely remove old one of neccesary
        if (new_pet) {
            if (pet) {
                delete pet;   // delete old pet to avoid memory leak
            }
            pet = new_pet;
    
            cout << "Your " << pet->get_type() << " named " << pet->get_name() << " has been adopted!\n";
            cout << "Press any key to continue...\n";
            string key;
            cin >> key;
            cout << endl;
        }
    }

//theres errors as the bird and cat files have not been created yet. 