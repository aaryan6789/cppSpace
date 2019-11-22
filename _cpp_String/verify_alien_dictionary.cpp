#include "_string.h"

int dict[26] = {0};

bool compare(string& s1 , string& s2){
    int len1 = s1.size();
    int len2 = s2.size();
    cout << "Comparing " << s1 << " & " << s2 << endl; 
    
    int j;
    for (j = 0; j < s1.size() and j < s2.size(); j++) { // compare character by character.
        if (dict[s1[j] - 'a'] > dict[s2[j] - 'a']) 
            return false;                           // wrong order.
        else if (dict[s1[j] - 'a'] < dict[s2[j] - 'a'])
            break;                                  // correct order.
    }
    
    if (j == s2.size())
        return false;       // word1 is longer than word2
    
    return true;
}

bool isAlienSorted(vector<string>& words, string order) {
    if (words.size() <= 1) 
        return true; // base case.
    

    // make a Map of the Alien Order
    for(int i = 0; i< order.size(); i++){
        dict[order[i] - 'a'] = i;
    }
    
    for(auto& i : dict){
        cout << i << " ";
    }
    
    for(int i = 0; i< words.size() - 1; i++){
        if(!compare(words[i], words[i+1])){
            return false;
        }
    }
    
    return true;
}
