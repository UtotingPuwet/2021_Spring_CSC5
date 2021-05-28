/*
    Author: Christian Fuentes
    Date:   May 11, 2021  3:35pm
    Purpose:Fixing aces to make it be 1 or 11 by force depending on value of
 * player's hand. 
 * Reconstructed the way the dealer draws cards by making him only
 * show the first value card but still draw the 2nd. 
 * Fixed the w/r bug because i put
 * '%\n' instead of quotation marks.
 * added more comments
 * 
 * May 12 added suits.
 * 
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <iomanip>     //Manipulate Library
#include <cmath>       //Math Library
#include <cstdlib>     //General Utilities Library
#include <fstream>     //File Library
#include <string>      //String Library
#include <ctime>       //Time Library

using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only
const float PERCENT = 100.00;
//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    srand (static_cast<unsigned int>(time(0)));
    //Declare variables
    int deck,              //deck variable using int and srand to make deck random.
        suit;              //suit variable using int and srand to make suit random.
    unsigned short p1Hand, //player hand variable
                   dealer, //dealer hand variable
                   menu,   //menu input variable
                   stndHit,//stand or hit variable (1 for hit, 2 for stand)
                   dealerP;//dealerP standing for Dealer prehand which is just a variable to print the value for dealer hand before the 2nd draw.
    bool           whoWon; //whoWon will be true if player wins and false if player loses.
    char           again;  //again variable to loop if player wants to continue playing.
    float          wr,     //winrate
                   wins,   //win tracker variable
                   losses, //loss tracker variable
                   draws;  //push tracker variable
    ofstream out;          //file output
    ifstream in;           //file input
    string welcome;        //welcome will read input from "welcome.txt"
    string suitStg;           //string suit
    //Initialize variables
    p1Hand = 0;            //initializing player hand
    dealer = 0;            //initializing dealer hand
    wins = 0;              //track wins
    losses = 0;            //track losses
    draws = 0;             //track draws/pushes
    again = 'y';           //making sure again is equal to y just in case
    wr = 0;                //initializing winrate
    
    
    //opening welcome.txt which is just a notepad text with a "Welcome
    //To Christian's Blackjack Game!" and assigning it to string variable "welcome"
    in.open("welcome.txt");
    getline(in,welcome);
    in.close();
    
    //start of the entire program
    do {
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
                return 0;

            }
            if (menu > 3) {
                cout << "Invalid option." << '\n';
            }
            //menu choice 1 is to  play the game
        } while (menu != 1);
        p1Hand = 0;  //reinitialize the variable values back to 0 for loop
        dealer = 0;  //reinitialize the variable values back to 0 for loop
        
        //this is to get player hand which loops twice to get the hand
            for (int i = 0; i<2; i++){            
        deck = rand()% 12 + 1;
        suit = random()% 4 + 1;
        if (suit == 1) {
            suitStg = " of spades";
        }
        else if (suit == 2) {
            suitStg = " of hearts";
        }
        else if (suit == 3) {
            suitStg = " of clubs";
        }
        else if (suit == 4) {
            suitStg = " of diamonds";
        }
        switch (deck){
            case 1: cout << "You got an ace" << suitStg << '\n';p1Hand += p1Hand>=11?1:11; break;
            case 2: cout << "You got a 2" << suitStg << '\n'; p1Hand += deck; break;
            case 3: cout << "You got a 3" << suitStg << '\n'; p1Hand += deck; break;
            case 4: cout << "You got a 4" << suitStg << '\n'; p1Hand += deck; break;
            case 5: cout << "You got a 5" << suitStg << '\n'; p1Hand += deck; break;
            case 6: cout << "You got a 6" << suitStg << '\n'; p1Hand += deck; break;
            case 7: cout << "You got a 7" << suitStg << '\n'; p1Hand += deck; break;
            case 8: cout << "You got a 8" << suitStg << '\n'; p1Hand += deck; break;
            case 9: cout << "You got a 9" << suitStg << '\n'; p1Hand += deck; break;
            case 10: cout << "You got a Jack" << suitStg << '\n'; p1Hand += 10; break;
            case 11: cout << "You got a  Queen" << suitStg << '\n'; p1Hand += 10; break;
            case 12: cout<< "You got a King"  << suitStg << '\n'; p1Hand += 10; break;
        }

    }
        cout << "Your hand is " << p1Hand << '\n' << '\n';
  //------------------------------------------------------------------------------
        //dealer draws 1 card and reveals the first card he gets and then 
        //will draw another card but not reveal it just yet until after player
        //decides to hit or stand.
  //------------------------------------------------------------------------------
        //dealer's first draw that is revealed
        deck = rand()% 12 + 1;
        //dealer's suit for the first card
        suit = rand()% 4 + 1;
        if (suit == 1) {
            suitStg = " of spades";
        }
        else if (suit == 2) {
            suitStg = " of hearts";
        }
        else if (suit == 3) {
            suitStg = " of clubs";
        }
        else if (suit == 4) {
            suitStg = " of diamonds";
        }
        switch (deck){
            case 1: cout << "Dealer got an ace" << suitStg << '\n'; dealer += dealer>=11?1:11; break;
            case 2: cout << "Dealer got a 2" << suitStg << '\n'; dealer += deck; break;
            case 3: cout << "Dealer got a 3" << suitStg << '\n'; dealer += deck; break;
            case 4: cout << "Dealer got a 4" << suitStg << '\n'; dealer += deck; break;
            case 5: cout << "Dealer got a 5" << suitStg << '\n'; dealer += deck; break;
            case 6: cout << "Dealer got a 6" << suitStg << '\n'; dealer += deck; break;
            case 7: cout << "Dealer got a 7" << suitStg << '\n'; dealer += deck; break;
            case 8: cout << "Dealer got a 8" << suitStg << '\n'; dealer += deck; break;
            case 9: cout << "Dealer got a 9" << suitStg << '\n'; dealer += deck; break;
            case 10: cout << "Dealer got a Jack" << suitStg << '\n'; dealer += 10; break;
            case 11: cout << "Dealer got a  Queen" << suitStg << '\n'; dealer += 10; break;
            case 12: cout << "Dealer got a King"  << suitStg << '\n'; dealer += 10; break;
        }
        //so now we make dealerP = dealer so that it can print the value of this card
        dealerP = dealer;
   //-----------------------------------------------------------------------------
        //dealer's second draw that is not revealed to the player.
        deck = rand()% 12 + 1;
        //dealer's second suit for his card
        suit = rand()% 4 + 1;
        if (suit == 1) {
            suitStg = " of spades";
        }
        else if (suit == 2) {
            suitStg = " of hearts";
        }
        else if (suit == 3) {
            suitStg = " of clubs";
        }
        else if (suit == 4) {
            suitStg = " of diamonds";
        }
        switch (deck){
            case 1:  dealer += dealer>=11?1:11; break;
            case 2:  dealer += deck; break;
            case 3:  dealer += deck; break;
            case 4:  dealer += deck; break;
            case 5:  dealer += deck; break;
            case 6:  dealer += deck; break;
            case 7:  dealer += deck; break;
            case 8:  dealer += deck; break;
            case 9:  dealer += deck; break;
            case 10: dealer += 10; break;
            case 11: dealer += 10; break;
            case 12: dealer += 10; break;
        }
//------------------------------------------------------------------------
        //checking to see if anyone got blackjack within their first two draws.
        
        if (p1Hand == 21){
            cout << "You got blackjack!!!\n";
            wins++;
        }
        else if (dealer == 21){
            cout << "You lose... dealer has " << dealer << '\n';
            losses++;
        }
        else {
            cout << "The Dealer's card is currently " << dealerP << '\n' << '\n';

            cout << "Enter 1 to hit \nEnter 2 to stand." << endl;
            cin>>stndHit;
            
            //if player hits then he can hit until his hand is over 21
            while (stndHit == 1 && p1Hand < 21){
                
                deck = rand()% 12 + 1;
                
                suit = rand()% 4 + 1;
                if (suit == 1) {
                    suitStg = " of spades";
                }
                else if (suit == 2) {
                    suitStg = " of hearts";
                }
                else if (suit == 3) {
                    suitStg = " of clubs";
                }
                else if (suit == 4) {
                    suitStg = " of diamonds";
                }
                switch (deck){
                    case 1: cout << "You got an ace" << suitStg << '\n'; p1Hand += p1Hand>=11?1:11; break;
                    case 2: cout << "You got a 2" << suitStg << '\n'; p1Hand += deck; break;
                    case 3: cout << "You got a 3" << suitStg << '\n'; p1Hand += deck; break;
                    case 4: cout << "You got a 4" << suitStg << '\n'; p1Hand += deck; break;
                    case 5: cout << "You got a 5" << suitStg << '\n'; p1Hand += deck; break;
                    case 6: cout << "You got a 6" << suitStg << '\n'; p1Hand += deck; break;
                    case 7: cout << "You got a 7" << suitStg << '\n'; p1Hand += deck; break;
                    case 8: cout << "You got a 8" << suitStg << '\n'; p1Hand += deck; break;
                    case 9: cout << "You got a 9" << suitStg << '\n'; p1Hand += deck; break;
                    case 10: cout << "You got a Jack" << suitStg << '\n'; p1Hand += 10; break;
                    case 11: cout << "You got a  Queen" << suitStg << '\n'; p1Hand += 10; break;
                    case 12: cout<< "You got a King"  << suitStg << '\n'; p1Hand += 10; break;
                }
                cout << "Your hand is now " << p1Hand << endl;
                cout << "Enter 1 to hit \nEnter 2 to stand" << endl;
                cin>>stndHit;
            }
            //while loop to have the dealer draw until 17.
            while (dealer < 17){
                deck = rand()% 12 + 1;
                suit = rand()% 4 + 1;
                if (suit == 1) {
                    suitStg = " of spades";
                }
                else if (suit == 2) {
                    suitStg = " of hearts";
                }
                else if (suit == 3) {
                    suitStg = " of clubs";
                }
                else if (suit == 4) {
                    suitStg = " of diamonds";
                }            
                switch (deck){
                    case 1: cout << "Dealer got an ace" << suitStg << '\n'; dealer += dealer>=11?1:11; break;
                    case 2: cout << "Dealer got a 2" << suitStg << '\n'; dealer += deck; break;
                    case 3: cout << "Dealer got a 3" << suitStg << '\n'; dealer += deck; break;
                    case 4: cout << "Dealer got a 4" << suitStg << '\n'; dealer += deck; break;
                    case 5: cout << "Dealer got a 5" << suitStg << '\n'; dealer += deck; break;
                    case 6: cout << "Dealer got a 6" << suitStg << '\n'; dealer += deck; break;
                    case 7: cout << "Dealer got a 7" << suitStg << '\n'; dealer += deck; break;
                    case 8: cout << "Dealer got a 8" << suitStg << '\n'; dealer += deck; break;
                    case 9: cout << "Dealer got a 9" << suitStg << '\n'; dealer += deck; break;
                    case 10: cout << "Dealer got a Jack" << suitStg << '\n'; dealer += 10; break;
                    case 11: cout << "Dealer got a Queen" << suitStg << '\n'; dealer += 10; break;
                    case 12: cout << "Dealer got a King"  << suitStg << '\n'; dealer += 10; break;
                }
            }
            cout << "The dealer's hand is now " << dealer << endl;
            whoWon = p1Hand>dealer?true:false; //ternary operator
            if (p1Hand > 21) {
                cout << "You busted." << '\n';
                losses++;
            }
            else if (dealer > 21){
                cout << "Dealer busted." << '\n';
                wins++;
            }
            else {
                if (dealer == p1Hand){
                    cout << "Push." << '\n';
                    draws++;
                }
                else if (whoWon == true){
                    cout << "You won! " << '\n';
                    wins++;
                }
                else if (whoWon == false){
                    cout << "Dealer wins." << endl;
                    losses++;
                }
            }
            
        }
        
        cout  << "Play again? (y for yes; n for no)" << endl;
        //if its not y then its not going again so doesnt really matter.
        cin >> again;
    } while (again == 'y');
        
    //Process, map inputs to outputs
    wr = wins/(wins+losses+draws); //calculating winrate by dividing wins by total games.
    //Display your initial conditions as well as outputs.
    
    out.open("ChristianFuentesBlackJack.txt",ios::out);
    out << "Your wins for this session are   : " << wins << '\n';
    out << "Your losses for this session are : " << losses << '\n';
    out << "Your draws for this session are  : " << draws << '\n';
    out << "Your winrate for this session is :"  << fixed << setprecision(2) << abs(wr*PERCENT) <<"%\n";
    out.close();
    
    //Exit stage right
    return 0;
}
