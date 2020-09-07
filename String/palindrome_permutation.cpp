#include "_string.h"

/**
 * CTCI
 * Palindrome Permutation:
 * Given a string, write a function to check if it is a permutation of a palindrome.
 * A palindrome is a word or phrase that is the same forwards and backwards.
 * A permutation is a rearrangement of letters.
 */

/* Algorithm:
 * 1. Start a Count Array of size 256 - NO_OF_CHARS possible
 * 2. Iterate over the array and count the number of occurrences of a particular
 *    character in the string.
 * 3. If the count array has the all even entries than it could be a palindrome,
 * 	  If the count array has 1 odd entry also then also it could be a palin.
 * 	  else its not gonna be a palindrome.
 */
/*
 * Time Complexity = O(n)
 * Space = O(k) where K is 256 if K distinct values
 */
#include <unordered_map>
void permutation_palindrome(string& str){
	int len = str.size();
	cout << "Length of " << str << " = " << len << endl;

	// int count[NO_OF_CHARS] = {0};
    unordered_map<char, int> count;

	for (int i = 0; i<len; i++){
		printf("str[i] = %c %d\n", str[i], str[i]);
		count[str[i]]++;		// Index = str[i]'s ASCII value e.g: 'a' = 66
	}

	int odd = 0;
	for (int j = 0; j<count.size(); j++){
		if(count[j] % 2 != 0) {
			odd++;
			cout << "odd = " << odd << " count[" << j << "] " << count[j] << endl;
		}

		if (odd > 1){
			cout << "Palindrome not possible.\n";
			return;
		}
	}

	printf("String Permutation can be a Palindrome.\n");
	return;
}
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