/*
    Author: Christian Fuentes
    Date:   April 30, 2021  8:43am
    Purpose:Seeing how to read and write to a file using a computer's date and
 * time
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <ctime>       //Time Library
#include <chrono>      //Clock Library
#include <fstream>     //File
#include <string>
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    ofstream out;
    ifstream in;
    string LOL;
    //Initialize variables

    //Process, map inputs to outputs
    
    //Display your initial conditions as well as outputs.
    in.open("input.txt");
    getline (in, LOL);
    in.close();
    
    cout << LOL;
    
    out.open("testing.txt",ios::app);
    out << LOL << endl;
    out.close();
    //Exit stage right
    return 0;
}
