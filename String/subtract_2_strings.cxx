#include <algorithm>
#include "_string.h"
using namespace std;

// string1 and string2 are both positive
// They do not have any alphabets in them
// They do not have preceding 0s
// Example: string1  = "1234", string2 = "1234"

bool isStr1Larger(string str1, string str2) {
    int len1 = str1.length();
    int len2 = str2.length();

    if(len1 > len2){
        return true;
    }
    else{
        return false;
    }

    if(len1 == len2){
        for(int i = 0; i< len1; i++){
            if(isdigit(str1[i] > isdigit(str2[i]){
                return true;
            }
            else if (isdigit(str1[i] < isdigit(str2[i]){
                return false;
            }
        }
    }

    return false;
}

// str1 - str2 
// 135 99 
// 1935 -  19 = 1916
string subtract(string big, string small) {
    int len1 = big.length();
    int len2 = small.length();
    string res;
    int carry = 0;

    int i = len1 -1;
    int j = len2 -1;

    while( j >= 0 && i >= 0){
        int rem = (isdigit(big[i] - carry) - isdigit(small[j]));
        if(rem < 0){
            rem += 10;
            carry = 1;
        }
        else{
            carry = 0;
        }

        res = (rem + '0') + res;
        
        i--;
        j--;
    }

    // Subtract the carry from the ith position and add to the res if valif
    while(i >= 0){
        res = (big[i] - carry) + res;
        carry = 0;
        i--;
    }

    return res;

}
                       
                       
string findDiff(string str1, string str2) {  
    if(isStr1Larger(str1, str2)){
        // Subtract str2 from str1
        return subtract(str1, str2);
    }
    else{
        // subtract str1 fronm str2
        return ('-' + subtract(str2, str1)) ;
    }
}