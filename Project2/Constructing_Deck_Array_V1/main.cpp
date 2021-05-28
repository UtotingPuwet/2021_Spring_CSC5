/*
    Author: Christian Fuentes
    Date:   May 27 2021, 10:27PM
    Purpose:Creating a deck of cards using an array.
    Version:First 
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <string.h>    //String Library
#include <cstdio>      //Standard Library
#include <ctime>       //Time Library
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    srand(static_cast<unsigned int>(time(NULL))); 
    int NUMCARDS = 52;
    
    string face[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    string card = "";
    for (int i = 0; i < 2; i++) {
        int randN = rand() % 13;
        cout << face[randN] <<  " ";
    }
    
    
    
    
    //Declare variables
    
    //Initialize variables
    
    //Process, map inputs to outputs
    
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
}
