#include "_string.h"
/**
 * Given a string check if it is Pangram or not.
 * A pangram is a sentence containing every letter in the English Alphabet.
 *
 * Examples :
 * "The quick brown fox jumps over the lazy dog ” is a Pangram [Contains all the characters from ‘a’ to ‘z’]
 * “The quick brown fox jumps over the dog" is not a Pangram [Doesn’t contains all the characters from ‘a’ to ‘z’, as ‘l’, ‘z’, ‘y’ are missing]
 */

void pangram(string s){
    int pano[5] = {0};    // {'a', 'b', 'c', 'd', 'e'};

    for(auto& ch : s){
        pano[ch - 'a']++;
    }

    for(int i =0; i< 5 ; i++){
        if(pano[i] == 0){
            cout << s << " Not a Pangram" << endl;
            return;
        }
    }

    cout << s << " is a Pangram" << endl;
    return;
}