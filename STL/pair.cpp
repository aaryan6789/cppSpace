#include "_stl.h"
#include <iostream>
#include <utility>

using namespace std;

// Templated function for Pair Printing
template <class T1, class T2>
void printPair(const pair<T1, T2>& p){
    cout << p.first << " ";
    cout << p.second << endl;
}



void stl_pair() {

    pair <int, int> pair1 (12, 20);
    cout << pair1.first << " " ;
    cout << pair1.second << endl ;

    pair1.first = 20;
    pair1.second = 22;

    cout << pair1.first << " " ;
    cout << pair1.second << endl ;

    // Pair with different data types
    pair <string, double> pair2 ("GeeksForGeeks", 1.23);

    cout << pair2.first << " " ;
    cout << pair2.second << endl ;

    printPair(pair1);
    printPair(pair2);

}