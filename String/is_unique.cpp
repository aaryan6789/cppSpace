#include "_string.h"
using namespace std;
/**
 * CTCI
 * is_unique
 * Implement  an algorithm to determine if  a  string  has all unique characters.
 * What if  you cannot use additional data structures?
 */

#include <unordered_map>
// Using Hash Map
void is_unique(string s){
    unordered_map<char, int> hash;

    for(int i = 0; i<s.length(); i++){
        hash[s[i] - ' ']++;

        if(hash[s[i] - ' '] == 2){
            cout << "Doesnt have Unique chars, as repeated char " << s[i] << " found ." << endl;
            return;
        }
    }
    cout << s << " has unique Chars" << endl;
    return;
}


// Not using extra Data Structure
// Sorting and Searching
// 1. Sort the string
// 2. Look for adjacent characters

void is_unique2(string s){
    sort(s.begin(), s.end());

    for(int i = 0; i< s.length() - 1; i++){
        if(s[i] == s[i+1]){
            cout << "Doesnt have Unique chars, as repeated char " << s[i] << " found ." << endl;
            return;
        }
    }
}

