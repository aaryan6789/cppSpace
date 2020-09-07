#include "_string.h"
 
/** LeetCode E | Frequent https://leetcode.com/problems/valid-palindrome/
 * Given a string, determine if it is a palindrome, considering only 
 * alphanumeric characters and ignoring cases.
 * 
 * Note: For the purpose of this problem,
 * we define empty string as valid palindrome.
 * 
 * Example 1:
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * Example 2:
 * Input: "race a car"
 * Output: false
 */

// Using 2 Pointers and isalnum STL method
// isalnum - is alphanumeric number (String ch)
// tolower
// toupper

bool isPalindrome(string s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
        if (!std::isalnum(s[left])) 
            left++;
        else if (!isalnum(s[right])) 
            right--;
        else {
            if (std::tolower(s[left]) != std::tolower(s[right])) 
                return false;
            left++; 
            right--;
        }
    }
    return true;
}


// Make a Rev String
bool isPalindrome2(string s) {
    if (s.size() <= 1) 
        return true;
    
    string str;
    
    for(int i=0; i<s.size(); i++){
        if (s[i]>='a' && s[i]<='z'){
            str += s[i];
        }
        else if(s[i]>='A' && s[i]<='Z'){
            str += (s[i]-'A' + 'a');
        }
        else if(s[i] >='0' && s[i]<='9'){
            str += s[i];
        }
    }
    
    int i, j;
    if (str.size()%2 == 1){
        i = j = str.size()/2;
    }
    else{
        i = str.size()/2-1;
        j = i+1;
    }
    
    while(i>=0){
        if (str[i] != str[j]){
            return false;
        }
        i--;
        j++;
    }
    return true;
}