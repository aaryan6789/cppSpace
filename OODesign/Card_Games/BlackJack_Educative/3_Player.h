#pragma once
#include "1_card.h"
#include "2_hand.h"

#include <list>

using namespace std;
// This file contains the various Actors for the System.
// We already scoped out the Identities and their respective functions.
enum class AccountStatus{
	ACTIVE,
	CLOSED,
	CANCELED,
	BLACKLISTED,
	BLOCKED
};

class Account {
    int id;
    string password;
    AccountStatus status;

    public:
        Account() {}

        bool resetPassword(string new_pass);
};

// This is a Base class from which the Other Actors will Inherit
class Person {
    private:
        string name;
        string address;
        string email;
        string phone;

        // Each person would have an account
        Account acc;        // Composition Design Pattern
    
    public:
        Person() {}

        Person(string name, string add, string em, string ph){
            this->name = name;
            this->address = add;
            this->email = em;
            this->phone = ph;
        }

        void details(){
            cout << "Person Details" << endl;
            cout << name << endl;
            cout << address << endl;
            cout << email << endl;
            cout << phone << endl;
            
        }
};

class BasePlayer {
    string id;
    string password;
    double balance;
    int accountStatus;
    Person person;
    list<Hand> hands;

public:
    bool resetPassword();

    list<Hand> getHands() {
        return hands;
    }

    void addHand(Hand hand) {
        return hands.push_back(hand);
    }

    void removeHand(Hand hand) {
        cout << "Remove the Hand" << endl;
        // hands.remove(hand);
    }
};

class Player : public BasePlayer {
    int bet;
    int totalCash;

public:
    Player(Hand hand) {
        addHand(hand);
    }
};


class Dealer : public BasePlayer {
    Hand hand;

public:
    int getTotalScore(){}
};