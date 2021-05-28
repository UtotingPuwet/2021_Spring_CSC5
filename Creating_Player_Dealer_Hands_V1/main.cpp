/*
    Author: Christian Fuentes
    Date:   April 19th, 2021  12:19am
    Purpose:Upgrading to make it print lines when certain number chosen using
             switch case
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <cstdlib>     //Random library
#include <ctime>       //Time library
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    srand (static_cast<unsigned int>(time(0)));
    //Declare variables
    int deck;
    unsigned short p1Hand, 
                   dealer,
                   wins,
                   losses;
    int stndHit;
    //Initialize variables
    p1Hand = 0;
    dealer = 0;
    wins = 0;
    losses = 0;
    
    
    
    for (int i = 0; i<2; i++){            
        deck = rand()% 12 + 1;
           
        switch (deck){
            case 1: cout << "You got an ace" << '\n'; p1Hand += deck; break;
            case 2: cout << "You got a 2" << '\n'; p1Hand += deck; break;
            case 3: cout << "You got a 3" << '\n'; p1Hand += deck; break;
            case 4: cout << "You got a 4" << '\n'; p1Hand += deck; break;
            case 5: cout << "You got a 5" << '\n'; p1Hand += deck; break;
            case 6: cout << "You got a 6" << '\n'; p1Hand += deck; break;
            case 7: cout << "You got a 7" << '\n'; p1Hand += deck; break;
            case 8: cout << "You got a 8" << '\n'; p1Hand += deck; break;
            case 9: cout << "You got a 9" << '\n'; p1Hand += deck; break;
            case 10: cout << "You got a Jack" << '\n'; p1Hand += 10; break;
            case 11: cout << "You got a  Queen" << '\n'; p1Hand += 10; break;
            case 12: cout<< "You got a King"  << '\n'; p1Hand += 10; break;
        }

    }
        cout << "Your hand is " << p1Hand << '\n' << '\n';
  //------------------------------------------------------------------------------
            
        deck = rand()% 12 + 1;
           
        switch (deck){
            case 1: cout << "Dealer got an ace" << '\n'; dealer += deck; break;
            case 2: cout << "Dealer got a 2" << '\n'; dealer += deck; break;
            case 3: cout << "Dealer got a 3" << '\n'; dealer += deck; break;
            case 4: cout << "Dealer got a 4" << '\n'; dealer += deck; break;
            case 5: cout << "Dealer got a 5" << '\n'; dealer += deck; break;
            case 6: cout << "Dealer got a 6" << '\n'; dealer += deck; break;
            case 7: cout << "Dealer got a 7" << '\n'; dealer += deck; break;
            case 8: cout << "Dealer got a 8" << '\n'; dealer += deck; break;
            case 9: cout << "Dealer got a 9" << '\n'; dealer += deck; break;
            case 10: cout << "Dealer got a Jack" << '\n'; dealer += 10; break;
            case 11: cout << "Dealer got a  Queen" << '\n'; dealer += 10; break;
            case 12: cout << "Dealer got a King"  << '\n'; dealer += 10; break;
        }  
    //Process, map inputs to outputs
    
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
}
