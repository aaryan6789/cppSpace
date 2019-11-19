#include <iostream>

using namespace std;
#include "_pointers.h"
/// Predict the output of following programs.
/// If there are compilation errors, then fix them.

int &fun1() {
    static int x = 10;
    return x;
}

int fun2(const int &x) {
    // x = 20;      // Compiler Error as const
    // x++;         // Compiler Error as const
    return x;
}

int Test1() {
    cout << "\n======= \nTEST 1\n======= " << endl;
    fun1() = 30;
    cout << "fun1()   = " << fun1() << endl;

    int x = 10;
    cout << "fun2(10) = " << fun2(x) << endl;;

    return 0;
}

