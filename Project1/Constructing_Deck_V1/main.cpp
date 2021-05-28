/*
    Author: Christian Fuentes
    Date:   April 17th, 2021  1:26pm
    Purpose:Messing around with srand and checking the percentages of pulling a number of a card
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

        int deck = rand()% 13 + 2;
        cout << deck;
    
    //Process, map inputs to outputs
    
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
}
