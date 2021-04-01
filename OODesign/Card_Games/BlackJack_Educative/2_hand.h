#pragma once
#include "1_card.h"

using namespace std;

class Hand {
    vector<BlackjackCard> cards;

public:
    vector<int> getScores() {
        vector<int> totals;
        totals.push_back(0);

        for (BlackjackCard card : cards) {
            vector<int> newTotals;
            for (int score : totals) {
                newTotals.push_back(card.getFaceValue() + score);

                if (card.getFaceValue() == 1) {
                    newTotals.push_back(11 + score);
                }
            }

            totals = newTotals;
        }

        return totals;
    }

    Hand(BlackjackCard c1, BlackjackCard c2) {
        this->cards.push_back(c1);
        this->cards.push_back(c2);
    }

    void addCard(BlackjackCard card) {
        cards.push_back(card);
    }

    // get highest score which is less than or equal to 21
    int resolveScore() {
        vector<int> scores = getScores();
        int bestScore = 0;

        for (int score : scores) {
            if (score <= 21 && score > bestScore) {
                bestScore = score;
            }
        }
        return bestScore;
    }

    vector<BlackjackCard> getCards(){
        return cards;
    }
};