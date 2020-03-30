#include<iostream>
using namespace std;

class Test {
private:
    int x;
public:
    Test(int x = 0) { this->x = x; }

    void change(Test *t) {
        // this = t;        // Error
        *this = *t;         // FIX
    }

    void print() {
        cout << "x = " << x << endl;
    }
};

#include<iostream>
using namespace std;

class Test2 {
private:
    int x;
    int y;
public:
    Test2(int x = 0, int y = 0) { this->x = x; this->y = y; }
    void setX(int a) { x = a; }
    void setY(int b) { y = b; }
    void destroy() { delete this; }
    void print() { cout << "x = " << x << " y = " << y << endl; }
};

int this_Test2() {
    // Test2 obj;
    Test2 *obj = new Test2;
    obj->destroy();
    obj->print();
    return 0;
}

int this_Test1() {
    cout << "This Keyword" << endl;
    Test obj(5);
    obj.print();
    Test *ptr = new Test (10);
    obj.change(ptr);
    obj.print();
    return 0;
}


int this_keyword() {
    this_Test1();
    this_Test2();
    return 0;
}