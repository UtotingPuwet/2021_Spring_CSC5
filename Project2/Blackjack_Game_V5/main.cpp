/*
    Author: Christian Fuentes
    Date:   May 28 2021, 3:36 PM
    Purpose:Setup the game (adding all other previous components)
    Version:First
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
    p1Hand = 0;
    filDeck(c,faceVal, NUMCARD);
    getCard(c,faceVal,NUMCARD,p1Hand);
   
    cout << endl << p1Hand;
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

void getCard(string c[], int faceVal[], int NUMCARD, int &p1Hand) {
    
    int pulCard = rand()%50;
    
    
    faceVal[pulCard];
    
    
    if (faceVal[pulCard] > 10) {
        p1Hand+= 10;
    }
    else if (faceVal == 0){
        if (p1Hand >= 11) {
            p1Hand += 1;
        }
        else p1Hand += 11;
    }
    else {
        p1Hand+= faceVal[pulCard];
    }
}

void menu() {
    //menu for the beginning
    ifstream in;
    ofstream out;
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