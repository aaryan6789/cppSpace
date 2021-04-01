#pragma once

#include <iostream>


using namespace std;

// This file contains the various Actors for the System.
// We already scoped out the Identities and their respective functions.

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


class Customer : public Person {
    private:
        string frequent_flyer_no;
        string cust_id;

    public:
        Customer() {}

        Customer(string name, string add, string em, string ph, string ffn, string cst_id): Person(name, add, em, ph) {
            this->frequent_flyer_no = ffn;
            this->cust_id = cst_id;
        }

        // API's
        void details(){
            Person::details();
            cout << frequent_flyer_no << endl;
            cout << cust_id << endl;
        }
};


class FrontDeskOfficer : public Person {
    private:
        string FDO_ID;

    public:
        FrontDeskOfficer() {}
};
