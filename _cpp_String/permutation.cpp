#include "_string.h"
/**
 * CTCI
 * Check Permutation:
 * Given  two strings, write a method to decide if one is a permutation of the other.
 */

#include <unordered_map>
void checkPermutation(string s1, string s2){
    if (s1.length() != s2.length()){
        cout << s1 << " and " << s2 << " are not Permutations!" << endl;
        return;
    }

    unordered_map<char, int> map;
    for(int i = 0; i<s1.length(); i++){
        map[s1[i]]++;
        map[s2[i]]--;
    }

    for(auto& item : map){
        if(item.second != 0){
            cout << s1 << " and " << s2 << " are not Permutations!" << endl;
            return;
        }
    }

    cout << s1 << " and " << s2 << " are Permutations!" << endl;
    return;
}

void checkPermutation1(string s1, string s2){
    if (s1.length() != s2.length()){
        cout << s1 << " and " << s2 << " are not Permutations!" << endl;
        return;
    }

    unordered_map<char, int> map;

    for(char& ch : s1){
        map[ch]++;
    }

    for(char& ch : s2){
        map[ch]--;
    }

    for(auto& item : map){
        if(item.second != 0){
            cout << s1 << " and " << s2 << " are not Permutations!" << endl;
            return;
        }
    }

    cout << s1 << " and " << s2 << " are Permutations!" << endl;
    return;
}