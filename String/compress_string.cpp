#include "_string.h"
#include <cstdlib>
/**
 * CTCI | Run Length Encoding
 * Given an input string, write a function that returns the Run Length Encoded
 * string for the input string.
 * For example,
 * if the input string is “wwwwaaadexxxxxx”, then the
 * function should return “w4a3d1e1x6”.
 */

/*
a) Pick the first character from source string.
b) Append the picked character to the destination string.
c) Count the number of subsequent occurrences of the picked character and append the count to destination string.
d) Pick the next character and repeat steps b) c) and d) if end of string is NOT reached.
*/

using namespace std;
void printRLE(string str){
    int n = str.length();
    for (int i = 0; i < n; i++) {
        // Count occurrences of current character
        int count = 1;
        while (i < n - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }
        cout << str[i] << count;            // Print character and its count
    }
}

/**
Given an array of characters, compress it in-place.
The length after compression must always be smaller than or equal to the original array.
Every element of the array should be a character (not int) of length 1.
After you are done modifying the input array in-place, return the new length of the array.

Follow up:
Could you solve it using only O(1) extra space?

Example 1:
Input:
["a","a","b","b","c","c","c"]
Output:
Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

Explanation:
"aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".

Example 2:
Input:
["a"]
Output:
Return 1, and the first 1 characters of the input array should be: ["a"]
Explanation:
Nothing is replaced.

Example 3:
Input:
["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output:
Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].

Explanation:
Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12".
Notice each digit has it's own entry in the array.


Note:

1. All characters have an ASCII value in [35, 126].
2. 1 <= len(chars) <= 1000.

Algorithm 1 : INPLACe and O(n)
 * Using 2 Pointers and O(n)
 */
int compress(vector<char>& chars) {
    if(chars.size() < 2)
        return chars.size();

    int  i = 0;
    int  j = 0;

    while(i < chars.size()) {
        chars[j] = chars[i];        // Inplace so keep the character on the first place
        int cnt = 0;
        while(i < chars.size() && chars[i] == chars[j]) {
            cnt++;
            i++;
        }

        if(cnt == 1) {          // Dont write anything if only 1 character
            j++;
        }
        else {
            string str = to_string(cnt);
            for(auto digit: str)
                chars[++j] = digit;
            j++;
        }
    }

    return j;
}



/**
 * Using Hash Map (Extra Space needed and O(n))
 */
#include <unordered_map>
int compress2(vector<char>& chars) {
    unordered_map<char, int> map;

    for(int i = 0; i< chars.size(); i++){
        map[chars[i]]++;
    }

    vector<char> result{};

    for(int i = 0; i<chars.size(); i++){
        if(chars[i] != chars[i+1]){
            result.push_back(chars[i]);
            cout << map[chars[i]] << endl;

            string s = to_string(map[chars[i]]); // Convert Int to string (For double digit or more only this will work)
            for (char& ch : s){
                result.push_back(ch);
            }
        }
    }

    for(auto& item : result){
        cout << item;
    }

    cout << endl;
    return result.size();
}

