#include "_string.h"

/**
 * 387. First Unique Character in a String | Leetcode Easy
 * Given a string, find the first non-repeating character in it and return it's index.
 * If it doesn't exist, return -1.
 *
 * Examples:
 * s = "leetcode" return 0.
 *
 * s = "loveleetcode",  return 2.
 *
 * Note: You may assume the string contain only lowercase letters.
 */

#include <unordered_map>
namespace first {
    // Using Hash Maps
    // Time Complexity = O(n)
    // Space complexity = O(Len)
    int firstUniqChar(string s) {
        std::unordered_map<char, int> hash;

        // Go through the String and put it in the map
        for(int i = 0; i< s.length() ; i++){
            hash[s[i]]++;
        }

        // for (auto x : hash){cout << x.first << x.second << endl;}

        // Go through the dtring again and look for the unique character
        for(int i = 0; i< s.length(); i++){
            if(hash[s[i]] == 1){
                cout << "\nFirst Unique Character = " << s[i] << " at " << i << endl;
                return i;
            }
        }

        cout << "No Unique Character in this string!" << endl;
        return -1;
    }
}

namespace optimized{

}