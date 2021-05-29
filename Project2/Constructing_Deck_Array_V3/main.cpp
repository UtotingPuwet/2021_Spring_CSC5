/*
    Author: Christian Fuentes
    Date:   May 28 2021, 4:01 PM
    Purpose:Making a deck of cards using vectors and arrays
    Version:Third
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
void filDeck(string [], int);
void pntDeck (string[], int);
void shuffle (string[], int);
//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    srand(static_cast<unsigned int>(time(NULL))); 
    int NUMCARD = 52;
    int deck [NUMCARD] = {};
    string c[NUMCARD];
    string face[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    string card = "";
    
    vector<string> faceV = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    vector<string> suitV = {"Clubs", "Spades", "Diamonds", "Hearts"};
    vector<string> color = {"Black", "Black", "Red", "Red"};

    
    //Declare variables
    filDeck(c,NUMCARD);
    //Initialize variables
    shuffle(c, NUMCARD);
    pntDeck(c, NUMCARD);
    //Process, map inputs to outputs
    
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
}

void filDeck (string c[], int NUMCARD) {
    string face[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    string suit[] = {"Clubs", "Spades", "Diamonds", "Hearts"};
    string color[] = {"Black", "Black", "Red", "Red"};
    for (int i = 0; i < NUMCARD; i++) {
        c[i] = color[i/13];
        c[i] += " ";
        c[i] += face[i%13];
        c[i] += " of ";
        c[i] += suit[i/13];
        
    }
}

void pntDeck (string c[], int NUMCARD) {
    int count = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            cout << c[count] << endl;
            count++;
        }
        cout << endl;
    } 
}

void shuffle (string c[], int NUMCARD) {
    for (int shfl = 0; shfl < 7; shfl++) {
        for (int i = 0; i < NUMCARD; i++) {
            int randVal = rand()%NUMCARD;
            string temp = c[i];
            c[i] = c[randVal];
            c[randVal] = temp;
        }
    }
}