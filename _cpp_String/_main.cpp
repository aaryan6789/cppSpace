#include "_string.h"
#include <iostream>
#include <string>
#include <iterator>
#include <vector>


using namespace std;
int main(){

    std::string s = "Strings by Harsh Sahu";
    cout << s << endl;
    cout << "Capacity " << s.capacity() << endl;
    cout << "Lenght " << s.length() << endl;

    // Resizing string using resize()
    s.resize(30);

    cout << "Capacity " << s.capacity() << endl;
    cout << "Length " << s.length() << endl;

    for (int i = 0; i< s.capacity(); i++){
        cout << s[i] ;
    }

    cout << "/"<< endl;

    std::string::iterator it;

    for (it = s.begin() ; it< s.end(); it++){
        cout << *it ;
    }

    first::firstUniqChar(s);

    vector<string> words = {"gin", "zen", "gig", "msg", "gaga", "gaga"};
    uniqueMorseRepresentations(words);


    string pan = "brack";
    // pangram(pan);

    string pan2 = "abcde";
    pangram(pan2);

    checkPermutation(pan2, pan);
    permutation_palindrome(pan);
    permutation_palindrome(s);

    vector<char> chars = {'a','a','b','b','c','c','c'};

    compress(chars);
    printRLE(pan);


    return 0;
}