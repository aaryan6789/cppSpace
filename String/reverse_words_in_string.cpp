#include "_string.h"

/** LeetCode Easy | 557 
 * Given a string, you need to reverse the order of characters in each word 
 * within a sentence while still preserving whitespace and initial word order.
 * 
 * Example 1:
 * Input: "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * 
 * Note: 
 * In the string, each word is separated by single space and there will not be 
 * any extra space in the string.
 */

// Using STL Reverse operation 
string reverseWords(string s) {
    if(s.size() <= 1){
        return s;
    }
    
    int front = 0;
    int n = s.size();
    
    for(int i = 0; i<= s.size(); i++){
        if(s[i] == ' ' || i == s.size()){
            std::reverse(&s[front], &s[i]);
            front = i+1;
        }
    }        
    
    return s;
}


// Using STL swap 
string reverseWords2(string s) {
    if(s.size() <= 1){
        return s;
    }
    
    int front = 0;
    int n = s.size();
    
    for(int i = 0; i<= s.size(); i++){
        if(s[i] == ' ' || i == s.size()){
            int last = i-1;
            while(front < last){
                swap(s[front] , s[last]);
                front++;
                last--;
            }
            front = i+1;
        }
    }        
    
    return s;
}