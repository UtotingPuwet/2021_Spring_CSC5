/*
    Author: Christian Fuentes
    Date:   May 29 2021, 10:06 AM
    Purpose:Re-make Game through functions and arrays and vectors.
    Version:Second
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <string.h>    //String Library
#include <cstdio>      //Standard Library
#include <ctime>       //Time Library
#include <vector>      //Vector Library
#include <fstream>     //File input/output
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
void menu();
void game (int, int[], string [], int=0, int=0);
void filDeck(vector<int> &, vector<string> &); //fill the vector deck
void getCard(vector<int> &, vector<string> &); //draw cards from the vector deck
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
    //Initialize 
    filDeck(c,faceVal,NUMCARD);
    shuffle(c,faceVal,NUMCARD);
    //outputs
    game(NUMCARD,faceVal,c);
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

void getCard(string c[], int faceVal[], int NUMCARD, int &p1Hand) {
    
    //declare variables
    int pulCard = rand()%50;
    //initialize and output
    faceVal[pulCard];
    
    //checking if player gets jack,king,queen
    if (faceVal[pulCard] > 10) {
        p1Hand+= 10;
    }
    //checking if player gets an ace and to see if hand is more than or equal to 11
    else if (faceVal[pulCard] == 1){
        if (p1Hand >= 11) {
            p1Hand += 1;
        }
        else p1Hand += 11;
    }
    else {
        p1Hand+= faceVal[pulCard];
    }
    
    cout << "You got a " << c[pulCard] << '\n';
}

void menu() {
    //menu for the beginning
    ifstream in;
    string welcome;
    unsigned short menu;
    
    //opening welcome.txt which is just a notepad text with a "Welcome
    //To Christian's Blackjack Game!" and assigning it to string variable "welcome"
    in.open("welcome.txt");
    getline(in,welcome);
    in.close();
   
        //start of the menu (just menu in this do while loop)
    do {
            cout << welcome;
            cout << "\n1. Play Blackjack.\n2. How to play.\n3. Quit game." << '\n';
            cin >> menu;
            //menu choice 2 which is the rules of the game
            if (menu == 2) {
                cout << "The goal of blackjack is to get a hand equal to 21." <<
                        "Each card is worth its numerical value, face cards " <<
                        "are worth 10, and ace is worth either 1 or 11.\n" << 
                        "Both the player and the dealer start with 2 cards " <<
                        "and the dealer flips " <<
                        "only 1 card up to show to the player. The player must " <<
                        "then decide if they want to hit (draw)\nor stand (not " <<
                        "draw).Press 1 to hit and 2 to stand.\n";
            }
            //menu choice 3 which is to quit
            if (menu == 3) {
                cout << "Goodbye!";
                exit(0);

            }
            if (menu > 3) {
                cout << "Invalid option." << '\n';
            }
    }while (menu != 1);
}

void filDeck (string c[], int faceVal[], int NUMCARD) {
    string face[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    string suit[] = {"Clubs", "Spades", "Diamonds", "Hearts"};
    for (int i = 0; i < NUMCARD; i++) {
        c[i] = face[i%13];
        c[i] += " of ";
        c[i] += suit[i/13];
        
        faceVal[i] = i%13 + 1;
    }
}

void pntDeck (string c[], int faceVal[], int NUMCARD) {
    int count = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            cout << c[count] << "and it's value is " << faceVal[count] << endl;
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

void game (int NUMCARD, int faceVal[], string c[], int p1Hand, int dealer) {
    getCard(c,faceVal,NUMCARD,p1Hand);
    getCard(c,faceVal,NUMCARD,p1Hand);
    cout << "Your hand is " << p1Hand;
}