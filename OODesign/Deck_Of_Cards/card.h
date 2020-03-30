#pragma once
#include <iostream>
using namespace std;

// Deck Of Cards
enum Suit { 
    SPADES = 1, 
    CLUBS,
    HEARTS,
    DIAMONDS
};

enum Rank {A, K, Q, J, _10, _9, _8, _7, _6, _5, _4, _3, _2};

class Card {
private:
    Suit s;
    int val;

public:
    // Default Constructor
    Card() {}
    // Method to return which suit is the card
    virtual Suit suit() const { 
		return s;
	}

    // Virtual method to return what is the val of the card
    virtual int value() const { 
		return val;
	}

    // Card Constructor
    Card(Suit st, const int v) : s(st), val(v) {};

    // Display
    void Display() {
        cout << s << " " << val << endl; 
    }
};


class BlackJackCard : public Card {
    public:
        int value() const {
            if(val <= 10){
                return val;
            }
            else if(val <= 13){
                return 10;
            }
        }
};