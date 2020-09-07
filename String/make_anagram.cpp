#include "_string.h"

#define MAX_CHARS 256


int makeAnagram(string a, string b) {
    vector<int> countA(26, 0);
    vector<int> countB(26, 0);
    
    for(int i = 0; i< a.length(); i++){
        countA[a[i] - 'a']++;
    }

    for(int i = 0; i< b.length(); i++){
        countB[b[i] - 'a']++;
    }

    int res = 0;
    for(int i = 0; i< MAX_CHARS; i++){
        res += abs(countA[i] - countB[i]);
    }

    return res;
}