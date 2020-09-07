#include <iostream>
#include "copy_constructor.h"

#include "inheritance.h"
#include "multiple_inheritance.h"


using namespace std;

// Default Constructors in C++

class A {
    public:
        A() {
            // User defined constructor
            cout << "A's Constructor" << endl;
        }

    public:
        int size;       // Un-Initialized data member
};

class B : public A {
    // Compiler should generate a Default Contructor for this class.
    // And it should insert a stub to call A's Constructor.
    // But it wont initialize any data of A class.
};

class C : public A {
    public:
        C() {
            // User Defined Default Constructor of C class.
            cout << "C's Constructor" << endl;

            // Compiler inserts stub to call A's Constructor
            // But it wont initialize the data of A class.
        }
};

class D {
    private:
        A a;        // <-- A class object as Data Member

    public:
        D(){
            // User defined constructor of Class D. Empty Body though.
            // Compiler inserts a stub to call A's Constructor as A's object is a data member of D.
            // Compiler wont initialize any data of A.
            cout << "D's Constructor" << endl;
        }
};


// Copy Constructor
// Contructor that initializes an object using another object of the same class.
// Syntax = class_name (const class_name& obj)          // Reference to the Object OKAY

// User Defined Copy Constructor = Deep Copy
// Default Copy Constructor  = Shallow Copy

class Point  {
    private:
        int x;
        int y;

    public:
        Point(int x1, int y1) {                 // Parameterized Constructor
            cout << "Point's Parameterized Constructor called" << endl;
            x = x1;
            y = y1;
        }

        Point (const Point& p2) {               // Copy Contructor
            cout << "Point's Copy Constructor called" << endl;
            x = p2.x;
            y = p2.y;
        }

        // Assignment Operator
        // An assignment operator is called when an already initialized object is assigned a new value
        // from another existing object.
        Point& operator = (const Point& p2){
            cout << "Point's Assignment operator called" << endl;
            return *this;
        }

        int getX() {
            cout << "Point x = " << x << endl;
            return x;
        }

        int getY(){
            cout << "Point y = " << y << endl;
            return y;
        }

};

class Something {
private:
    int m_value;

public:
    Something() {
        m_value = 1; // error: const vars can not be assigned to
    }
};
int this_keyword();

int main(){

    Something s;

    this_keyword();

    cout << " ---- ---- Default Constructor ---- ----" << endl;
    cout << "Object of B" << endl;
    B b;
    cout << endl;

    cout << "Object of C" << endl;
    C c;
    cout << endl;

    cout << "Object of D" << endl;
    D d;
    cout << endl;

    // Parameterized Constructor is called here
    Point p1(10, 20);
    cout << " ---- ---- Copy Constructor ---- ----" << endl;

    // Copy contrucor is called for object p2
    Point p2 = p1;

    cout << "Point 1" << endl;
    p1.getX();
    p1.getY();

    cout << "Point 2" << endl;
    p2.getX();
    p2.getY();

    // Copy Constructor and assignment Operator
    // A copy constructor is used to initialize a newly declared variable from an existing variable.
    // This makes a deep copy like assignment, but it is somewhat simpler:
    //   1. There is no need to test to see if it is being initialized from itself.
    //   2. There is no need to clean up (eg, delete) an existing value (there is none).
    //   3. A reference to itself is not returned.

    // And assignment operator is called when an already initialized object is assigned a new value
    // from another existing object.

    B b1 = b;       // <- Copy Constructor
    b1 = b;         // <- Assignment Operator
    b.size = 10;
    cout << "B size = " << b.size << endl;

    Point p3(9, 2);
    p3 = p1;    // Calls Assignment operatorsame as p3.operator=(p1)

    cout << "Point 3" << endl;
    p3.getX();
    p3.getY();

    cout << "\nString Class for Copy Constructor" << endl;
    String str1("GeeksQuiz");
    String str2 = str1;

    str1.print(); // what is printed ?
    str2.print();

    str2.change("GeeksforGeeks");

    str1.print(); // what is printed now ?
    str2.print();

    cout << " ---- ---- Inheritance ---- ----" << endl;

    Child ch_obj;           // An object of Child class has all data members and member functions of class Parent.
    ch_obj.child_id = 12;
    ch_obj.parent_id = 44;

    cout << "Child ID = " << ch_obj.child_id << endl;
    cout << "Parent ID = " << ch_obj.parent_id << endl;

    // --------- Vehicle Example ----------

    Car car_obj;

    Car2 car2_obj;

    cout << " ---- ---- Multiple Inheritance ---- ----" << endl;

    CMI cmi;

    TA ta1(30);

    // DMI2 dmi2;
    // dmi2.print();


    return 0;
}