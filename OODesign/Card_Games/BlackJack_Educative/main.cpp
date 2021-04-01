#include <iostream>
#include "1_card.h"
#include "2_hand.h"
#include "3_Player.h"
#include "4_game.h"

int main(){
    Deck d;
    d.printDeck();

    Shoe s(3);
    s.dealCard();

    // Player p1;
    // Dealer d;
    // Game g;


    return 0;
}