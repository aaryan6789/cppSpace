#include "_string.h"



// Complete the alternatingCharacters function below.
int alternatingCharacters(string s) {

    // Make a frequency map
    vector<int> map(2, 0);

    for(int i = 0; i<s.length(); i++){
        map[s[i] - 'A']++;
    }

    // In case only A or only B are present
    if(map[0] > 1 && map[1] == 0){
        return map[0] - 1;
    }
    else if(map[1] > 1 && map[0] == 0){
        return map[1] - 1;
    }

    int res = 0;
    for(int i = 0; i< s.length() -1 ; i++){
        if(s[i] == s[i+1]){
            res++;
        }
    }

    return res;


}