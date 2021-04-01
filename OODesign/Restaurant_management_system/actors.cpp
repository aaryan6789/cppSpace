// # For simplicity, we are not defining getter and setter functions. The reader can
// # assume that all class attributes are private and accessed through their respective
// # public getter methods and modified only through their public methods function.
#include "constants.h"
#include <ctime>

class Account {
    private:
        int id;
        string password;
        string address;
        AccountStatus status;

    public:
        Account() {}        // Always better to have a Default constructor written into the code

        Account( int id, string password, string address, AccountStatus status) {
            this->id = id;
            this->password = password;
            this->address = address;
            this->status = AccountStatus::ACTIVE;
        }

        void reset_password() {
            cout << "Reset Password" << endl;
        }

};

// Inheritance : Person <--- Employee <--- Receptionist
class Person {
    private:
        string name;
        string email;
        int phone;

    public:
        Person () {}
        Person(string name, string email, int phone){
            this->name = name;
            this->email = email;
            this->phone = phone;
        }
};

class Employee : public Person {
    private:
        int employee_id;
        time_t date_joined;
        Account account;

    public:
        Employee () : Person() {}
        Employee(int id, Account& act, string name, string email, int phone): Person(name, email, phone) {
            this->employee_id = id;
            this->date_joined = time(0);
            this->account = act;
        }
};


class Receptionist : public Employee {
    private:
    public:
        Receptionist(int id, Account act, string name, string email, int phone) : Employee(id, act, name, email, phone) {}

        void create_reservation();
        bool search_customer(string name);
};


class Manager : public Employee {
    private:
    public:
        Manager(int id, Account act, string name, string email, int phone) : Employee(id, act, name, email, phone) {}
        bool add_employee();
};

class Chef : public Employee {
    private:
    public:
        Chef(int id, Account act, string name, string email, int phone) : Employee(id, act, name, email, phone) {}

        bool take_order();
};

class Customer : public Person {
    public:
        Customer(string name, string email, int phone): Person(name, email, phone){}
};