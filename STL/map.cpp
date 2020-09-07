#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>

#include "_stl.h"

using namespace std;

// Templatized Function for Printing unordered Map
template <class T1, class T2>
void print_map(const map<T1,T2>& map){
    cout << setw (5) << "Key" << " -> " << "Val" << endl;
    for (auto x : map){
        cout << setw (5) << x.first << " -> " << x.second <<endl;
    }
    cout << endl;
}

void stl_map(){
    // empty map container
    map<int, int> gquiz1;

    // insert elements in random order
    gquiz1.insert(pair<int, int>(1, 40));
    gquiz1.insert(pair<int, int>(2, 30));
    gquiz1.insert(pair<int, int>(3, 60));
    gquiz1.insert(pair<int, int>(40, 20));
    gquiz1.insert(pair<int, int>(5, 50));
    gquiz1.insert(pair<int, int>(6, 50));
    gquiz1.insert(pair<int, int>(7, 10));

    // printing map gquiz1
    map<int, int>::iterator itr;

    cout << "\nmap gquiz1 is : \n";
    cout << "KEY\tELEMENT\n";
    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
        cout  << itr->first << '\t' << itr->second << '\n';
    }

    // Declare the map
    map<char, int> mymap;

    // Compare the key.
    map<char, int>::key_compare mycomp = mymap.key_comp();

    mymap.insert({'A', 32});
    mymap.insert({'B', 33});
    mymap.insert({'C', 34});
    mymap.insert({'D', 35});

    print_map(mymap);

    // when 2 is present
    auto it = mymap.lower_bound(20);
    cout << "The lower bound of key 200 is ";
    cout << (*it).first << " " << (*it).second << endl;

    cout << endl;

}