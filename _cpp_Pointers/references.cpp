#include <iostream>

using namespace std;
#include "_pointers.h"
/// Predict the output of following programs. If there are compilation errors, then fix them.

int &fun1() {
    static int x = 10;
    return x;
}

int fun2(const int &x) {
    // x = 20;
    return x;
}

int Test1() {
    fun1() = 30;
    cout << "Test 1 = " << fun1() << endl;

    int x = 10;
    cout << "Test 2 = " << fun2(x) << endl;;

    return 0;
}

