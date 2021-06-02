/*
    Author: Christian Fuentes
    Date:   May 31 2021, 5:55 PM
    Purpose:Re-make Game through functions and arrays and vectors.
    Version:4
 * 
 * Adding a betting system
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
const float PERCENT = 100.00;
//Function Prototypes
void getCard(string [], int [], int, int&);             //will be used to draw cards for player
void shuffle(string [], int [], int);                   //shuffle the array deck
void pntDeck(string [], int [], int);                   //print the array deck
void filDeck(string [], int [], int);                   //fill the array deck
void selSort(string [], int [], int);                   //sort the array with select sort algorithm
void menu();                                            //just a welcome message :]
void filDeck(vector<int> &, vector<string> &);          //fill the vector deck
void getCard(vector<int> &, vector<string> &, short &); //draw cards from the vector deck. Will be used for dealer
void shuffle(vector<int> &, vector<string> &);          //shuffle the vector deck
void bubSort(vector<int> &, vector<string> &);          //sort the vector with bubble sort algorithm
void game (int, int[], string [], vector<int> &, vector<string> &, int &, int &,short &,int=0, short=0);
bool check21 (short);                                   //check 21 for dealer
bool check21 (int);                                     //check 21 for player
void stndHit (int, int [], string c[], int &);          //player stand or hit or double down
void dealDrw(vector<int> &, vector<string> &, short &);          //dealer auto draw if under 17
void initBet(int &, int &);                             //initialize the bet money
int betUpdt (int, int &, int);                            //update bet depend in number. 0 = lose, 1 = win, 2 = push, 3 = blackjack
//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    srand(static_cast<unsigned int>(time(NULL))); 

    //Declare variables
    short dealer,
          wins;
    const int NUMCARD = 52;
    int p1Hand,
        bet,
        total,
        faceVal[NUMCARD];
    string c[NUMCARD];
    char again;
    vector<int> deck;
    vector<string> card;
    //Initialize variables
    total = 0;
    again == 'y';
    //Initialize decks
    do {
        filDeck(c,faceVal,NUMCARD);
        shuffle(c,faceVal,NUMCARD);
        filDeck(deck,card);
        shuffle(deck,card);

        //Initialize bet/total
        initBet(bet,total);

        //Begin game
        game(NUMCARD,faceVal,c,deck,card,bet,total,wins);

        //Sort deck after game is finished
        selSort(c,faceVal,NUMCARD);
        bubSort(deck,card);
        cout << "Would you like to play again?\n";
        cin>>again;
    } while (again == 'y' || again == 'Y');
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------
//functions below will belong to anything with vectors.
//-------------------------------------------------------------------------------------------------------------------------------------------------

void filDeck(vector<int> &deck, vector<string> &card) {
    vector<string> face = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    vector<string> suit = {"Clubs", "Spades", "Diamonds", "Hearts"};
    
    for (int i = 0; i < 52; i++) {
        card.push_back(face[i%13] + " of " + suit[i/13]);
        deck.push_back(i%13+1);
    }
}

void getCard(vector<int> &deck, vector<string> &card, short &dealer) {
    int randVal = rand()%13 + 1;
    
    if (dealer == 0) {
        cout << "Dealer got " << card[randVal] << '\n';
    }
    dealer += deck[randVal];
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

//-------------------------------------------------------------------------------------------------------------------------------------------------
//functions below will belong to anything with arrays.
//-------------------------------------------------------------------------------------------------------------------------------------------------

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

//-------------------------------------------------------------------------------------------------------------------------------------------------
//End of array functions.
//-------------------------------------------------------------------------------------------------------------------------------------------------

void game (int NUMCARD, int faceVal[], string c[],  vector<int> &deck, vector<string> &card, int &bet,int &total, short &wins,int p1Hand, short dealer) {
    bool whoWon;
    
    getCard(c,faceVal,NUMCARD,p1Hand);
    getCard(c,faceVal,NUMCARD,p1Hand);
    cout << "Your hand is " << p1Hand << '\n';
    getCard(deck,card,dealer);
    getCard(deck,card,dealer);
    if (dealer == 21 && p1Hand == 21) {
        cout << "Both people got blackjack. Push.\n";
        cout << "Your total is now " << betUpdt(bet,total,2) << '\n';
        return;
    }
    if (check21(dealer) == true) {
        cout << "Dealer got blackjack. \n"; 
        cout << "Your total is now " << betUpdt(bet,total,0) << '\n';
        return;
    }
    if (check21(p1Hand) == true) {
        cout << "Player got blackjack. \n";
        cout << "Your total is now " << betUpdt(bet,total,3) << '\n';
        wins++;
        return;
    }
    stndHit(NUMCARD,faceVal,c,p1Hand);
    dealDrw(deck, card, dealer);
    cout << "Dealer's hand is now " << dealer << '\n';
    if (dealer == p1Hand) {
        cout << "Push.";
        cout << "Your total is now " << betUpdt(bet,total,2) << '\n';
        return;
    }
    whoWon = p1Hand>dealer?true:false;
    if (p1Hand > 21) {
        cout << "You busted. You lost.\n";
        cout << "Your total is now " << betUpdt(bet,total,0) << '\n';
    }
    else if (dealer > 21) {
        cout << "Dealer busted. You won.\n";
        cout << "Your total is now " << betUpdt(bet,total,1) << '\n';
        wins++;
    }
    else {
        if (whoWon == true) {
            cout << "You won!\n";
            cout << "Your total is now " << betUpdt(bet,total,1) << '\n';
            wins++;
        }
        else {
            cout << "You lost!\n";
            cout << "Your total is now " << betUpdt(bet,total,0) << '\n';
        }
    }
}

void dealDrw(vector<int> &deck, vector<string> &card, short &dealer) {
    while (dealer < 17) {
        getCard(deck, card, dealer);
    }
}

void stndHit (int NUMCARD, int faceVal[], string c[], int &p1Hand) {
    unsigned short choice;
    while (p1Hand <= 21 && choice != 2){
        cout << "\nPress 1 to hit\nPress 2 to stand\nPress 3 to double down\n";
        cin>>choice;
        switch (choice) {
            case 1: getCard(c,faceVal,NUMCARD,p1Hand); cout <<"Your hand is now " << p1Hand << '\n';break;
            case 2: return;
        }
    }
    
}

bool check21 (short dealer) {
    if (dealer == 21) return true;
    else {
        return false;
    }
}

bool check21 (int p1Hand) {
    if (p1Hand == 21) return true;
    else {
        return false;
    }
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

void initBet(int &bet, int &total) {
    if (total == 0) {
        cout << "How much total are we planning on using to bet today?\n";
        cin >> total;
    }
    cout << "How much would you like to bet? Can't bet over $50,000.\n";
    cin>>bet;
    if (bet > 50000) {
        cout << "Your bet is now $50,000." << endl;
        bet = 50000;
    }
    
    total = total-bet; 
}

int betUpdt (int bet, int &total, int update) {
    /* 0 = loss
     * 1 = win
     * 2 = push
     * 3 = blackjack
     */
    if (update == 0) {
        total = total;
        return total;
    }
    else if (update == 1) {
        total +=(bet*2);
        return total;
    }
    else if (update == 2) {
        total += bet;
        return total;
    }
    else if (update == 3) {
        total += (bet*2.5);
        return total;
    }
    return 0;
}