#include "Game.h"
#include <iostream>

using namespace std;

    void showWelcomeMenu() {
        std::cout << " -----------------------\n" ;
        std::cout << "Welcome to the Adoption Centre\n" ;
        std::cout << " -----------------------\n" ;
        std::cout << "1) Start Game\n";
        std::cout << "3) Exit\n" ;
        std::cout << "Please choice an option:  \n";


    }
//if 1) is chosen, a new game is started 
    void showChoiceMenu () {
        std::cout << "------Welcome to the Adoption Centre-------\n";
        std::cout << "What pet would you like to own?\n" ;
        std::cout << "Enter 1 for Dog\n";
        std::cout << "Enter 2 for Cat\n";
        std::cout << "Enter 3 for Bird\n";

        int choice;
        cin >> choice;

        if (choice ==1){
            string name;
            cout << endl << "___________________________________";
            cout << endl << endl << "Congrats you have chosen a Dog! They are loyal companions and love attention"<< endl << endl;
            // below will be listed attributes about the dogs hunger, happiness and sleep levels. All types of pets will evolve equally once they reach certain levels
            std::cout << "As dogs are naturally much happier animals, they will start the game with 100 happiness\n";
            std::cout << "Because of their happiness, they always seem to be hungry, so they will start the game with a hunger level of 50\n";
            std::cout << "What would you like to name your new companion?\n";

            cin >> name;

            pet = new Dog (name, "Dog");
            if(!check(pet)){
                add(pet);
                std::cout << " Your " << pet-> getType() << " " << pet->getName() << "has been adopted!\n";
                std::cout << "Please press any key to to continue!\n";
                string key;
                cin>> key;
                return false;
                cout << endl;
                

            }

        }
        else{

            if(choice==2){
                string name;
                std::cout << "______________________________";
                std::cout << "Congrats you have chosen a cat!\n";
                std::cout << ""
            }
        }

    }
    