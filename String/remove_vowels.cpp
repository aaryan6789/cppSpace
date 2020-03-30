#include "_string.h"

using namespace std;
/**
 * Remove Vowels from a String  | Leetcode Easy
 *
 * Given a string S, remove the vowels 'a', 'e', 'i', 'o', and 'u' from it,
 * and return the new string.
 *
 * Example 1:
 *
 * Input: "leetcodeisacommunityforcoders"
 * Output: "ltcdscmmntyfrcdrs"
 *
 * Example 2:
 * Input: "aeiou"
 * Output: ""
 *
 * Note:
 * S consists of lowercase English letters only.
 * 1 <= S.length <= 1000
 */

/** 1. Linear Scan, Strig size extra space
 *  - Linearly go through the sting and populate the resultant string
 */
string removeVowels(string s) {
    int len = s.size();
    string res = "";        // Result String

    // for(int i=0; i< len; i++){
    //     if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' ){
    //         res = res + s[i];
    //     }
    // }

    // Faster by for (auto &ch ) way
    for (auto &ch : s){
        if(ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u' ){
            res = res+ ch;
        }
    }

    return res;
}

/** Using String STL Functions
 *
 */
string removeVowels2(string S) {
	std::string chars = "aeiou";

	for (char c: chars) {
		S.erase(std::remove(S.begin(), S.end(), c), S.end());
	}

	return S;
}


