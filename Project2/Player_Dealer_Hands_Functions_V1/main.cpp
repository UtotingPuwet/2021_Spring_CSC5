/*
    Author: Christian Fuentes
    Date:   May 28 2021, 11:09 AM
    Purpose:Creating player and dealer hands.
    Version:First
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <string.h>
#include <cstdio>
#include <ctime>
#include <vector>
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes
void getCard(int&);            //will be used to draw cards for player
void getCard(unsigned short&); //will be used to draw cards for dealer
//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    srand(static_cast<unsigned int>(time(NULL))); 
    unsigned short dealer = 0;
    int p1Hand = 0;
    
    getCard(dealer);
    cout << '\n';
    getCard(p1Hand);
    
    //Declare variables
    cout << endl << dealer << endl;
    cout << p1Hand;
    //Initialize variables
    
    //Process, map inputs to outputs
    
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
}

void getCard(unsigned short &dealer) {
    
    //declare variables
    int cardSC;  //an int to use for generating random suit and color
    int faceVal; //an int to use for generating random face and value;
    vector<string> face = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    vector<string> suit = {"Clubs", "Spades", "Diamonds", "Hearts"};
    vector<string> color = {"Black", "Black", "Red", "Red"};
    
    //initialize variables
    faceVal = rand()%13;
    cardSC = rand()%4;
    
    //output
    cout << color[cardSC] << " "<<face[faceVal] << " of " << suit[cardSC];
    if (faceVal > 10) {
        dealer+= 10;
    }
    else if (faceVal == 0){
        if (dealer >= 11) {
            dealer += 1;
        }
        else dealer += 11;
    }
    else {
        dealer+= faceVal;
    }
}

void getCard(int &p1Hand) {
    
    //declare variables
    int cardSC;  //an int to use for generating random suit and color
    int faceVal; //an int to use for generating random face and value;
    string face[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    string color[4] = {"Black", "Black", "Red", "Red"};
    string suit[4] = {"Clubs", "Spades", "Diamonds", "Hearts"};
    
    //initialize variables
    faceVal = rand()%13;
    cardSC = rand()%4;
    
    //output
    cout << color[cardSC] << " "<<face[faceVal] << " of " << suit[cardSC];
    if (faceVal > 10) {
        p1Hand+= 10;
    }
    else if (faceVal == 0){
        if (p1Hand >= 11) {
            p1Hand += 1;
        }
        else p1Hand += 11;
    }
    else {
        p1Hand+= faceVal;
    }
}