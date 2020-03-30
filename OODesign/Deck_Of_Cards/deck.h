#include "card.h"
using namespace std;
// Class To represent a Deck of Cards
class Deck {
public:
    // Characteristics of a Deck
    static const int SUITS_PER_DECK = 4;
    static const int CARDS_PER_SUIT = 13;

private:
    Card cards[SUITS_PER_DECK * CARDS_PER_SUIT];
    int topCard;

public:
    // Construct a Default Deck of Cards
    Deck() {
        int topCard = 0;        // As No card is dealt yet
        int index = 0;
        for (int i = 1; i <= SUITS_PER_DECK; ++i) {
            for (int j = 1; j <= CARDS_PER_SUIT; ++j) {
                // index = i * CARDS_PER_SUIT + j;
                Card temp(Suit(i), j);

                cards[index] = temp;
                index += 1;
            }
        }
    }

    void print_deck(){
        for(auto& c : cards){
            cout << c.suit() << " " << c.value() << endl;
        }
    }

    // Shuffle a Deck of Cards
    void Shuffle() {
        int bagSize = SUITS_PER_DECK * CARDS_PER_SUIT;
        int index = 0;
        // srand(time(NULL));
        while (bagSize) {
            index = rand() % bagSize;
            swap(cards[--bagSize], cards[index]);
        }

        topCard = 0;				// no cards dealt yet
    }

    // Deal a Card from the Deck
    // deal one card from the top of the deck, and return it
    // NOTE -- NEED to add in error check for exhausted deck.
    // (and decide on how to handle).
    Card DealCard() {
        Card deal;
        deal = cards[topCard];	// next deal position
        topCard++;			// increment deal position
        return deal;
    }

    // Get the Top Most card
    int TopCard() const {
        return topCard;
    }
};