#include <iostream>

using namespace std;

// Inheritance
// The capability of a class to derive properties and characteristics from another class is called Inheritance.
// Base Class
//      |
//      |
//      V
// Derived Class

/// Modes of inheritance

class AI {
    public:
        int x;

    protected:
        int y;

    private:
        int z;
};

class BI : public AI {
    // x is public
    // y is protected
    // z is not accessible from BI (Private (Hidden))
};

class CI : protected AI {
    // x is protected
    // y is protected
    // z is not accessible from CI (Private (Hidden))
};

class DI : private AI {
    // x is private
    // y is private
    // z is not accessible from DI (Private (Hidden))
};

/// Type Of Inheritance

// 1. Single Inheritance
class Parent {
    public:
        int parent_id;
};

class Child : public Parent {
    public:
        int child_id;
};

/// An Object of Child class will get access to all the data members and member functions of class Parent.


class Vehicle {
    public:
        Vehicle() {                         // Default Constructor
            cout << "This is Vehicle " << (typeid(this).name()) << endl;
        }
};

class Car : public Vehicle {
    public:
        Car(){
            cout << "This is a Car " << (typeid(this).name()) << endl;
        }
};


// 2. Multiple Inheritance
// a class can inherit from more than one classes. i.e one sub class is inherited from more than one base classes.
//
//      Base Class 1      Base Class 2
//              \             /
//               \           /
//                \         /
//               Derived Class

class FourWheeler {
    public:
        FourWheeler() {
            cout << "This is a Four Wheeler " << endl;
        }
};

// Derived Class from 2 Base Classes Vehicle and FourWheeler
class Car2 : public Vehicle, public FourWheeler {
    public:
};

// Creating object of Derived class will invokde the constructor of Base Classes (In the same order)

// 3. Multi Level Inheritance
// In this type of inheritance, a derived class is created from another derived class.
//          Base Class 2
//              |
//              |
//              V
//          Base Class 1
//              |
//              |
//              V
//         Derived Class
