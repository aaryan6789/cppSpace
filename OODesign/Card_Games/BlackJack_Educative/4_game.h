#include <iostream>
#include "1_card.h"
#include "2_hand.h"
#include "3_Player.h"

using namespace std;

class Game {
    Player player;
    Dealer dealer;
    Shoe shoe;
    int MAX_NUM_OF_DECKS = 3;

    void playAction(char action, Hand hand) {
        switch(action) {
            case 'h':   // Hit 
                hit(hand); 
                break;
            
            case 's': // Split
                split(hand); 
                break;
            
            case 'p':   // Stand Pat 
                break; //do nothing
            
            case 't':   // Stand  
                stand(); 
                break;
            
            default: 
                cout << "Wrong input" << endl;
        }
    }

    void hit(Hand hand) {
        hand.addCard(shoe.dealCard());
    }

    void stand() {
        int dealerScore = dealer.getTotalScore();
        int playerScore = player.getTotalScore();
        list<Hand> hands = player.getHands();
        
        for(Hand hand : hands) {
            int bestScore = hand.resolveScore();
            if(playerScore == 21){
                //blackjack, pay 3:2 of the bet
            } 
            else if (playerScore > dealerScore) {
                // pay player equal to the bet
            } 
            else if (playerScore < dealerScore) {
                // collect the bet from the player
            } 
            else { //tie
                // bet goes back to player
            }
        }
    }

    void split(Hand hand) {
        vector<BlackjackCard> cards = hand.getCards();
        player.addHand(Hand(cards[0], shoe.dealCard()));
        player.addHand(Hand(cards[1], shoe.dealCard()));
        player.removeHand(hand);
    }

    Game(Player player, Dealer dealer) {
        this->player = player;
        this->dealer = dealer;
        Shoe shoe(MAX_NUM_OF_DECKS);
    }

    void getBetFromUI() {
        cout << "Enter Bet " << endl;
    }

    void start() {
        player.placeBet(getBetFromUI());

        Hand playerHand(shoe.dealCard(), shoe.dealCard());
        player.addToHand(playerHand);

        Hand dealerHand = new Hand(shoe.dealCard(), shoe.dealCard());
        dealer.addToHand(dealerHand);

        while(true){
            list<Hand> hands = player.getHands();
            
            for(Hand hand : hands) {
                string action = getUserAction(hand);
                playAction(action, hand);
                
                if(action == "stand") {
                    break;
                }
            }
        }
    }

    void main(String args[]) {
        Player player;
        Dealer dealer;
        Game game(player, dealer);
        
        game.start();
    }
};

