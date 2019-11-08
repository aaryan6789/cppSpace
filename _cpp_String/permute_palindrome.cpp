#include "_string.h"

bool canPermutePalindrome(string s) {
    int count[256] = {0};

    for (int i = 0; i<s.size(); i++){
        count[s[i] - ' ']++;		// Index = str[i]'s ASCII value e.g: 'a' = 66
    }

    int odd = 0;
    for (int j = 0; j<256; j++){
        if(count[j] % 2 != 0) {
            odd++;
        }

        if (odd > 1){
            return false;
        }
    }

    return true;
}