/*
    Author: Christian Fuentes
    Date:   May 28 2021, 5:06 PM
    Purpose:Making searching and sorting algorithms
    Version:5
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
void getCard(string [], int [], int, int&); //will be used to draw cards for player
void getCard(unsigned short&);              //will be used to draw cards for dealer
void shuffle(string [], int [], int);       //shuffle the array deck
void pntDeck(string [], int [], int);       //print the array deck
void filDeck(string [], int [], int);       //fill the array deck
void selSort(string [], int [], int);       //sort the array with select sort algorithm
void bubSort(string [], int [], int);       //sort the array with bubble sort algorithm
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
    //Initialize variables
    filDeck(c,faceVal, NUMCARD);
    
    //Process, map inputs to outputs
    shuffle(c,faceVal,NUMCARD);
    
    
    bubSort(c,faceVal,NUMCARD);
    pntDeck(c,faceVal,NUMCARD);
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
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
        for (int j = 0; j < 6; j++) {
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

void selSort(string c[], int faceVal[], int NUMCARD) {
    for (int i = 0; i < NUMCARD-1; i++) {
        int minIndx = i;
        for (int j = i+1; j < NUMCARD;j++ ) {
           
            if (faceVal[j] > faceVal[minIndx]) {
                minIndx = j;
            }
            if (minIndx != i) {
                int temp = faceVal[minIndx];
                faceVal[minIndx] = faceVal[j];
                faceVal[j] = temp;
                
                string tempS = c[minIndx];
                c[minIndx] = c[j];
                c[j] = tempS;
            }
        }
    }
}

void bubSort(string c[], int faceVal[], int  NUMCARD) {
    bool swap;
    do {
        
        swap = false;
        for (int i = 0; i < NUMCARD-1; i++) {
            if (faceVal[i] > faceVal[i+1]) {
                int temp = faceVal[i];
                faceVal[i] = faceVal[i+1];
                faceVal[i+1] = temp;
                swap = true;
            }
        }
    }while(swap);
}