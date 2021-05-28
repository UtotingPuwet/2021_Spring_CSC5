/*
    Author: Christian Fuentes
    Date:   May 2nd-8th 2021  12:54pm
    Purpose:Adding into reading and writing wins, losses, and push/draw into a 
 * .txt file named "winrate."
 * 
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <cstdlib>     //Random Library
#include <ctime>       //Time Library
#include <cmath>       //Math Library
#include <fstream>     //File Library
#include <string>      //String Library
#include <iomanip>     //Manipulate Library
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
    int deck;              //deck variable using int and srand to make deck random
    unsigned short p1Hand, //player hand variable
                   dealer, //dealer hand variable
                   wins,   //win tracker variable
                   losses, //loss tracker variable
                   draws,  //push tracker variable
                   menu,   //menu input variable
                   stndHit;//stand or hit variable (1 for hit, 2 for stand)
    bool           whoWon; //whoWon will be true if player wins and false if player loses.
    char           again;  //again variable to loop if player wants to continue playing.
    float          wr;     //winrate
    ofstream out;          //file output
    ifstream in;           //file input
    string welcome;        //welcome will read input from "welcome.txt"
    //Initialize variables
    p1Hand = 0;            //initializing player hand
    dealer = 0;            //initializing dealer hand
    wins = 0;              //track wins
    losses = 0;            //track losses
    draws = 0;             //track draws/pushes
    again = 'y';           //making sure again is equal to y just in case
    
    
    in.open("welcome.txt");
    getline(in,welcome);
    in.close();
    
    
    do {
        do {
            cout << welcome;
            cout << "\n1. Play Blackjack.\n2. How to play.\n3. Quit game." << '\n';
            cin >> menu;
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
            if (menu == 3) {
                cout << "Goodbye!";
                return 0;

            }
        } while (menu != 1);
        p1Hand = 0;  //reinitialize the variable values back to 0 for loop
        dealer = 0;  //reinitialize the variable values back to 0 for loop
            for (int i = 0; i<2; i++){            
        deck = rand()% 12 + 1;
           
        switch (deck){
            case 1: cout << "You got an ace" << '\n'; p1Hand += deck; break;
            case 2: cout << "You got a 2" << '\n'; p1Hand += deck; break;
            case 3: cout << "You got a 3" << '\n'; p1Hand += deck; break;
            case 4: cout << "You got a 4" << '\n'; p1Hand += deck; break;
            case 5: cout << "You got a 5" << '\n'; p1Hand += deck; break;
            case 6: cout << "You got a 6" << '\n'; p1Hand += deck; break;
            case 7: cout << "You got a 7" << '\n'; p1Hand += deck; break;
            case 8: cout << "You got a 8" << '\n'; p1Hand += deck; break;
            case 9: cout << "You got a 9" << '\n'; p1Hand += deck; break;
            case 10: cout << "You got a Jack" << '\n'; p1Hand += 10; break;
            case 11: cout << "You got a  Queen" << '\n'; p1Hand += 10; break;
            case 12: cout<< "You got a King"  << '\n'; p1Hand += 10; break;
        }

    }
        cout << "Your hand is " << p1Hand << '\n' << '\n';
  //------------------------------------------------------------------------------
        //next part is for dealer to draw 1 card only and then draw again after player
        //decides if they want to hit or stand
            
        deck = rand()% 12 + 1;
           
        switch (deck){
            case 1: cout << "Dealer got an ace" << '\n'; dealer += deck; break;
            case 2: cout << "Dealer got a 2" << '\n'; dealer += deck; break;
            case 3: cout << "Dealer got a 3" << '\n'; dealer += deck; break;
            case 4: cout << "Dealer got a 4" << '\n'; dealer += deck; break;
            case 5: cout << "Dealer got a 5" << '\n'; dealer += deck; break;
            case 6: cout << "Dealer got a 6" << '\n'; dealer += deck; break;
            case 7: cout << "Dealer got a 7" << '\n'; dealer += deck; break;
            case 8: cout << "Dealer got a 8" << '\n'; dealer += deck; break;
            case 9: cout << "Dealer got a 9" << '\n'; dealer += deck; break;
            case 10: cout << "Dealer got a Jack" << '\n'; dealer += 10; break;
            case 11: cout << "Dealer got a  Queen" << '\n'; dealer += 10; break;
            case 12: cout << "Dealer got a King"  << '\n'; dealer += 10; break;
        }

        if (p1Hand == 21){
            cout << "You got blackjack!!!";
            wins++;
        }
        else if (dealer == 21){
            cout << "You lose... dealer has " << dealer;
            losses++;
        }
        else {
            cout << "The Dealer's hand is currently " << dealer << '\n' << '\n';

            cout << "Enter 1 to hit \nEnter 2 to stand." << endl;
            cin>>stndHit;
            
            //if player hits then he can hit until his hand is over 21
            while (stndHit == 1 && p1Hand < 21){
                deck = rand()% 12 + 1;
                switch (deck){
                    case 1: cout << "You got an ace" << '\n'; p1Hand += deck; break;
                    case 2: cout << "You got a 2" << '\n'; p1Hand += deck; break;
                    case 3: cout << "You got a 3" << '\n'; p1Hand += deck; break;
                    case 4: cout << "You got a 4" << '\n'; p1Hand += deck; break;
                    case 5: cout << "You got a 5" << '\n'; p1Hand += deck; break;
                    case 6: cout << "You got a 6" << '\n'; p1Hand += deck; break;
                    case 7: cout << "You got a 7" << '\n'; p1Hand += deck; break;
                    case 8: cout << "You got a 8" << '\n'; p1Hand += deck; break;
                    case 9: cout << "You got a 9" << '\n'; p1Hand += deck; break;
                    case 10: cout << "You got a Jack" << '\n'; p1Hand += 10; break;
                    case 11: cout << "You got a  Queen" << '\n'; p1Hand += 10; break;
                    case 12: cout<< "You got a King"  << '\n'; p1Hand += 10; break;
                }
                cout << "Your hand is now " << p1Hand << endl;
                cout << "Enter 1 to hit \nEnter 2 to stand" << endl;
                cin>>stndHit;
            }
            do {
                deck = rand()% 12 + 1;
                switch (deck){
                    case 1: cout << "Dealer got an ace" << '\n'; dealer += deck; break;
                    case 2: cout << "Dealer got a 2" << '\n'; dealer += deck; break;
                    case 3: cout << "Dealer got a 3" << '\n'; dealer += deck; break;
                    case 4: cout << "Dealer got a 4" << '\n'; dealer += deck; break;
                    case 5: cout << "Dealer got a 5" << '\n'; dealer += deck; break;
                    case 6: cout << "Dealer got a 6" << '\n'; dealer += deck; break;
                    case 7: cout << "Dealer got a 7" << '\n'; dealer += deck; break;
                    case 8: cout << "Dealer got a 8" << '\n'; dealer += deck; break;
                    case 9: cout << "Dealer got a 9" << '\n'; dealer += deck; break;
                    case 10: cout << "Dealer got a Jack" << '\n'; dealer += 10; break;
                    case 11: cout << "Dealer got a  Queen" << '\n'; dealer += 10; break;
                    case 12: cout << "Dealer got a King"  << '\n'; dealer += 10; break;
                }
            }while (dealer < 17);
            cout << "The dealer's hand is " << dealer << endl;
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
        cin >> again;
    } while (again == 'y');
        
    //Process, map inputs to outputs
    wr = wins/(wins+losses+draws);
    //Display your initial conditions as well as outputs.
    
    out.open("ChristianFuentesBlackJack.txt",ios::out);
    out << "Your wins for this session are   : " << wins << '\n';
    out << "Your losses for this session are : " << losses << '\n';
    out << "Your draws for this session are  : " << draws << '\n';
    out << "Your winrate for this session is :"  << setprecision(2) <<fixed << wr*PERCENT <<'%\n';
    out.close();
    
    //Exit stage right
    return 0;
}
