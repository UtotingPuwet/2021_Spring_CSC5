/*
    Author: Christian Fuentes
    Date:   April 18th, 2021  11:14pm
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
   
    //Initialize variables
    for (int i = 0; i<2; i++){            
        int deck = rand()% 12 + 1;
           
        switch (deck){
            case 1: cout << "You got an ace" << '\n'; break;
            case 2: cout << "You got a 2" << '\n'; break;
            case 3: cout << "You got a 3" << '\n'; break;
            case 4: cout << "You got a 4" << '\n'; break;
            case 5: cout << "You got a 5" << '\n'; break;
            case 6: cout << "You got a 6" << '\n'; break;
            case 7: cout << "You got a 7" << '\n'; break;
            case 8: cout << "You got a 8" << '\n'; break;
            case 9: cout << "You got a 9" << '\n'; break;
            case 10: cout << "You got a Jack" << '\n'; break;
            case 11: cout << "You got a  Queen" << '\n'; break;
            case 12: cout<< "You got a King"  << '\n'; break;
        }
                
    }
    
    
    //Process, map inputs to outputs
    
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
}
