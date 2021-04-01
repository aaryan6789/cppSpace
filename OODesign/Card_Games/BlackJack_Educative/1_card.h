#pragma once
#include <iostream>
#include <vector>

using namespace std;

enum class SUIT {
  HEART = 1, SPADE, CLUB, DIAMOND
};

/*
 * Card
 * The following class encapsulates a playing card
 */
class Card {
    SUIT suit;
    int faceValue;

    public:
        SUIT getSuit() {
            return suit;
        }

        int getFaceValue() {
            return faceValue;
        }

        // Card Class Constructor
        Card(SUIT suit, int faceValue) {
            this->suit = suit;
            this->faceValue = faceValue;
        }
};


// BlackjackCard: BlackjackCard inherits from Card class to represent a blackjack card
class BlackjackCard : public Card {
    int gameValue;      // Game Value is specific to Black jack Game.
                        // BJ gameValue are : Ace : 1 or 11, J , K , Q = 10, and Other Cards = 1 to 9

public:
    int getGameValue() {
        return gameValue;
    }

    // Black Jack Card Constructor
    BlackjackCard(SUIT suit, int faceValue) : Card(suit, faceValue) {
        this->gameValue = faceValue;
        
        if(this->gameValue > 10) {
            this->gameValue = 10;
        }
    }
};


// Deck
// A Deck has 52 cards. 13 of Each Suit.

class Deck {
   vector<BlackjackCard> cards;

public:
    Deck() {
        for(int value = 1 ; value <= 13 ; value++){
            for(int s = 1; s <= 4; s++){
                BlackjackCard c(static_cast<SUIT>(s), value);
                this->cards.push_back(c);
            }
        }
    }

    vector<BlackjackCard> getCards() {
        return cards;
    }

    void printDeck(){
        cout << "Deck Size is " << cards.size() << endl;
        for(int i = 0; i<cards.size(); i++){
            cout << cards[i].getFaceValue() << " " << int(cards[i].getSuit()) << endl;
        }
    }
};


class Shoe {
    vector<BlackjackCard> cards;
    int numberOfDecks;

public:
    void createShoe() {
        for(int decks = 0 ; decks < numberOfDecks ; decks++){
            vector<BlackjackCard> dc = Deck().getCards();
            for(int i = 0; i<dc.size(); i++){
                cards.push_back(dc[i]);
            }
            dc.clear();
        }
    }

    Shoe(int numberOfDecks) {
        this->numberOfDecks = numberOfDecks;
        createShoe();
        shuffle();

        cout << "Shoe Created with " << cards.size() << " Cards" << endl;
    }

    void shuffle() {
        int cardCount = cards.size();
        
        for (int i = 0; i < cardCount ; i++){
            int r = rand() % 13;
            int index = r * (cardCount-i-1);
            swap(i, index);
        }
    }

    void swap(int i, int j) {
        BlackjackCard temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }

    //Get the next card from the shoe
    BlackjackCard dealCard() {
        if(cards.size() == 0 ){
            createShoe();
        }

        BlackjackCard dealtCard = cards.back();
        cards.pop_back();
        cout << "Dealing " << dealtCard.getGameValue() << " " << (int)dealtCard.getSuit() << endl;
        return dealtCard;
    }
};
