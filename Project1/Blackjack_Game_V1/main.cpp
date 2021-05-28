/*
    Author: Christian Fuentes
    Date:   April 21th, 2021  12:44pm
    Purpose:Creating winners and making the full blackjack game without loop.
 * (not putting a menu yet). 

 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <cstdlib>     //Random library
#include <ctime>       //Time library
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    srand (static_cast<unsigned int>(time(0)));
    //Declare variables
    int deck;
    unsigned short p1Hand, 
                   dealer,
                   wins,
                   losses,
                   draws;
    int stndHit;
    //whoWon will be true if player wins and false if player loses.
    bool whoWon;               
    //Initialize variables
    p1Hand = 0;
    dealer = 0;
    wins = 0;
    losses = 0;
    
    
    
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
            whoWon = p1Hand>dealer?true:false;
            if (p1Hand > 21) {
                cout << "You busted." << '\n';
            }
            else if (dealer > 21){
                cout << "Dealer busted." << '\n';
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
        
    //Process, map inputs to outputs
    
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
}
