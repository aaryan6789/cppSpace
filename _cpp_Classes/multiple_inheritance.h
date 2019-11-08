#include <iostream>

using namespace std;

// Inheritance
// The capability of a class to derive properties and characteristics from another class is called Inheritance.

// Multiple Inheritance is a feature of C++ where a class can inherit from more than one classes.
// The constructors of inherited classes are called in the same order in which they are inherited.
// For example, in the following program, B’s constructor is called before A’s constructor.

// The destructors are called in reverse order of constructors.

class AMI {
    public:
        AMI() {
            cout << "A's constructor called" << endl;
        }
};

class BMI {
    public:
        BMI(){
            cout << "B's constructor called" << endl;
        }
};

class CMI : public BMI, public AMI  {       // Note the order
    public:
        CMI(){
            cout << "C's constructor called" << endl;
        }
};


/// Issues in Multiple Inheritance
// 1. Diamond problem
// When 2 Derived classes of a class has a common Base Class.

// Solution is Virtual Class as Base Class

class Person {
    public:
        Person(int x) {
            cout << "Person::Person(int ) called" << endl;
        }
        Person(){
            cout << "Person::Person() called" << endl;
        }
};

class Faculty : virtual public Person {
    public:
        Faculty(int x):Person(x) {
            cout << "Faculty::Faculty(int ) called" << endl;
        }
};

class Student : virtual public Person {
    public:
        Student(int x):Person(x) {
            cout << "Student::Student(int ) called" << endl;
        }
};

class TA : public Faculty, public Student {
    public:
        TA(int x): Student(x), Faculty(x), Person(x) {
            cout << "TA::TA(int ) called" << endl;
        }
};


// Question 1: Predict the output
class AMI2 {
        static int x;
    public:
        void setX(int i) {
            x = i;
        }
        static void print() {
            cout << x;
        }
};

class BMI2:  public AMI2 {
    public:
        BMI2(){
            setX(10);
        }
};

class CMI2:  public AMI2 {
    public:
        CMI2(){
            setX(20);
        }
};

class DMI2: public BMI2, public CMI2 {

};

// I say nothing or 20