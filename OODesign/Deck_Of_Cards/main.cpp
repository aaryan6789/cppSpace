#include <iostream>
#include <ctime>
#include "card.h"
#include "deck.h"
using namespace std;


// Using the Above Card and Deck Classes we can simulate a Card Game
// The Popular Games are : Black Jack, Poker, UNO etc

// Lets Make a Black Jack Game
// What is Black Jack game ?
// 2 or more cards on Player and 2 or More Cards at dealer
// If dealer gets 21 he wins, if Player gets 21 he wins
// If player has bigger number then dealer then player wins

// So What claasess you need for Game? 
// --> We would need 2 more classes:
// class Player --> Dealer can be derived from it
// Class Hand

// int main() {
//     Card C(SPADES, 3);
//     Deck d;

//     // d.print_deck();
//     d.Shuffle();
//     d.print_deck();

//     cout << d.TopCard() << endl;

//     Card c = d.DealCard();
//     cout << c.suit() << " " << c.value() << endl;

//     return 0;
// }