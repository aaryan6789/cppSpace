/* main.cpp  * Created on: Aug 12, 2018 * Author: Harsh */


/*Goal: Examine pointers!*/

#include <iostream>
#include<string>

#include "_pointers.h"
using namespace std;

int main() {
    int a = 54;

    std::cout << "a = " << a << "\n";
    std::cout << "address of a is at &a = " << &a << "\n";

    /** Pointer Derefrencing:
     * If we have a pointer and want to access the value stored in that address?
     * This process is called dereferencing, and it is indicated by adding the
     * operator * before the variable's name.
     * This same operator should be used to declare a variable that is meant
     * to store a pointer.
     **/

    // this is a pointer that holds the address of the variable 'a'.
    // if 'a' was a float, rather than int, so should be its pointer.
    int * pointerToA = &a;

    // If we were to print pointerToA, we'd obtain the address of 'a':
    std::cout << "pointerToA stores " << pointerToA << '\n';

    // If we want to know what is stored in this address, we can dereference pointerToA:
    std::cout << "pointerToA points to " << * pointerToA << '\n';

    /* Pointer to Integers and Characters     */
    int * pointerI;
    int number;
    char character;
    char * pointerC;
    std::string sentence;
    std::string *pointerS;

    pointerI = &number;
    *pointerI = 45;

    pointerC = &character;
    *pointerC = 'f';

    pointerS = &sentence;
    *pointerS = "Hey look at me, I know pointers!";
    cout << "sentence = " << sentence << endl;
    cout << "pointerS = " << *pointerS << endl;

    std::cout << "number    = " << number    << endl;
    std::cout << "character = " << character << endl;
    std::cout << "sentence  = " << sentence  << endl;


    cout << "\n======== \nReferences\n======== " << endl;
    a = 100;
    int &ref = a;

    ref++;
    a++;
    cout << "a = " << a << " refa " << ref << " or " << *(&ref) << endl;
    cout << "Addresss of a   = " << &a << " \nAddress of refa = " << &(ref) << endl;

    int b = 55;
    int& refb = a;

    refb = b;

    cout << "b = " << b << " refb " << refb << endl;


    unique_pointer();
    passing_unique_pointers();
    // shared_pointer();


    return 0;
}
