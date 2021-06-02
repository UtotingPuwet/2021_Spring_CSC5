/*
    Author: Christian Fuentes
    Date:   May 29 2021, 5:07 PM
    Purpose:Made it so the vector's in the program are more like the array functions
 * in which they can fill a deck (52) and be shuffled/sorted. Also going to
 * make bubble sort used on the vector rather than the array
    Version:6
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <string.h>    //String Library
#include <cstdio>      //Standard Library
#include <ctime>       //Time Library
#include <vector>      //Vector Library
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes
void getCard(string [], int [], int, int&);    //getcard from array deck. Will be used to draw cards for player
void shuffle(string [], int [], int);          //shuffle the array deck
void pntDeck(string [], int [], int);          //print the array deck
void filDeck(string [], int [], int);          //fill the array deck
void selSort(string [], int [], int);          //sort the array with select sort algorithm
void bubSort(vector<int> &, vector<string> &);        //sort the vector with bubble sort algorithm
void filDeck(vector<int> &, vector<string> &); //fill the vector deck
void getCard(vector<int> &, vector<string> &); //draw cards from the vector deck
void shuffle(vector<int> &, vector<string> &); //shuffle the vector deck
void getCard(vector<int> &, vector<string> &); //get card from the vector deck. Will be used for dealer
void pntDeck(vector<int> &, vector<string> &); //print the vector deck
//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    srand(static_cast<unsigned int>(time(NULL))); 

    //Declare variables
    unsigned short dealer;
    int NUMCARD = 52;
    int p1Hand,
        faceVal[NUMCARD];
    
    string c[NUMCARD];
    vector<int> deck;
    vector<string> card;
    //Initialize variables
    filDeck(deck,card);
    shuffle(deck,card);
    pntDeck(deck,card);
    
    bubSort(deck,card);
    pntDeck(deck,card);
    //Process, map inputs to outputs
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
}

void filDeck(vector<int> &deck, vector<string> &card) {
    vector<string> face = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    vector<string> suit = {"Clubs", "Spades", "Diamonds", "Hearts"};
    
    for (int i = 0; i < 52; i++) {
        card.push_back(face[i%13] + " of " + suit[i/13]);
        deck.push_back(i%13+1);
    }
}

void getCard(vector<int> &deck, vector<string> &card) {
    int randVal = rand()%13 + 1;
    
    cout << card[randVal] << "and it's value is "<< deck[randVal];
}

void  shuffle (vector<int> &deck, vector<string> &card) {
    for (int shfl = 0; shfl < 7; shfl++) {
        for (int i = 0; i < 52; i++) {
            int randVal = rand()%52;
            string temp = card[i];
            card[i] = card[randVal];
            card[randVal] = temp;
            
            int itemp = deck[i];
            deck[i] = deck[randVal];
            deck[randVal] = itemp;
        }
    }
}

void filDeck (string c[], int faceVal[], int NUMCARD) {
    string face[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    string suit[] = {"Clubs", "Spades", "Diamonds", "Hearts"};
    string color[] = {"Black", "Black", "Red", "Red"};
    for (int i = 0; i < NUMCARD; i++) {
        c[i] = color[i/13];
        c[i] += " ";
        c[i] += face[i%13];
        c[i] += " of ";
        c[i] += suit[i/13];
        
        faceVal[i] = i%13 + 1;
    }
}

void pntDeck (string c[], int faceVal[], int NUMCARD) {
    int count = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 4; j++) {
            cout << c[count] << " and it's value is " << faceVal[count] << endl;
            count++;
        }
        cout << endl;
    } 
}

void shuffle (string c[], int faceVal[], int NUMCARD) {
    for (int shfl = 0; shfl < 7; shfl++) {
        for (int i = 0; i < NUMCARD; i++) {
            int randVal = rand()%NUMCARD;
            string temp = c[i];
            c[i] = c[randVal];
            c[randVal] = temp;
            
            int itemp  = faceVal[i];
            faceVal[i] = faceVal[randVal];
            faceVal[randVal] = itemp;
        }
    }
}

void bubSort(vector<int> &deck, vector<string> &card) {
    bool swap;
    do {
        
        swap = false;
        for (int i = 0; i < 52-1; i++) {
            if (deck[i] > deck[i+1]) {
                int temp = deck[i];
                deck[i] = deck[i+1];
                deck[i+1] = temp;
                swap = true;
                
                string tempS = card[i];
                card[i] = card[i+1];
                card[i+1] = tempS;
            }
        }
    }while(swap);
}

void pntDeck (vector<int> &deck, vector<string> &card) {
    int count = 0;
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            cout << card[count] << " and it's value is " << deck[count] << endl;
            count++;
        }
        cout << endl;
    } 
}