#include <iostream>

using namespace std;

class A {
    int x;
public:
    void setX(int i) {
        x = i;
    }

    virtual void print(){
        cout << x << endl;
    }
};

class B : virtual public A {
public:
    B() {
        cout << "B's Constructor" << endl;
        setX(10);
    }
};

class C : virtual public A {
public:
    C() {
        cout << "C's Constructor" << endl;
        setX(20);
    }
};


class D : public B, public C {
};

int main() {
    D d;
    d.print();
}