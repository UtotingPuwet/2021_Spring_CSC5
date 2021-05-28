/*
    Author: Christian Fuentes
    Date:   May 28, 2021  1:14pm
    Purpose:file io welcome message and state rules using functions
    Version:First and Last
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <fstream>
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes
void menu ();
//Execution Begins Here
int main(int argc, char** argv) {
    
    menu();
    
    //Exit stage right
    return 0;
}

void menu() {
    ifstream in;
    ofstream out;
    string welcome;
    unsigned short menu;
    
    //opening welcome.txt which is just a notepad text with a "Welcome
    //To Christian's Blackjack Game!" and assigning it to string variable "welcome"
    in.open("welcome.txt");
    getline(in,welcome);
    in.close();
   
        //start of the menu (just menu in this do while loop)
    do {
            cout << welcome;
            cout << "\n1. Play Blackjack.\n2. How to play.\n3. Quit game." << '\n';
            cin >> menu;
            //menu choice 2 which is the rules of the game
            if (menu == 2) {
                cout << "The goal of blackjack is to get a hand equal to 21." <<
                        "Each card is worth its numerical value, face cards " <<
                        "are worth 10, and ace is worth either 1 or 11.\n" << 
                        "Both the player and the dealer start with 2 cards " <<
                        "and the dealer flips " <<
                        "only 1 card up to show to the player. The player must " <<
                        "then decide if they want to hit (draw)\nor stand (not " <<
                        "draw).Press 1 to hit and 2 to stand.\n";
            }
            //menu choice 3 which is to quit
            if (menu == 3) {
                cout << "Goodbye!";
                exit(0);

            }
            if (menu > 3) {
                cout << "Invalid option." << '\n';
            }
    }while (menu != 1);
}
