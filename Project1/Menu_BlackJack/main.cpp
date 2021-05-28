/*
    Author: Christian Fuentes
    Date:   April 18th, 2021  3:14pm
    Purpose:Making menu for the game
 */

//System Libraries
#include <iostream>    //Input/Output Library

using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    char menu,
         again;
    //Initialize variables
    again = "y";
    //Process, map inputs to outputs
    do {
        cout << "Welcome to Christian Fuentes' Blackjack game" << '\n';
        cout << "1. Play Blackjack.\n2. How to play.\n3. Quit game." << '\n';
        cin >> menu;
        
        
        
        cout  << "Play again?";
    } while (again == "y");
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
}
