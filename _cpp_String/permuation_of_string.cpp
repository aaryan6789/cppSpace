#include "_string.h"
#include <map>


// Using Arrays as Map
bool match(vector<int>& s1, vector<int>& s2){
    if(s1.size() != s2.size()){
        return false;
    }

    for(int i = 0; i< s1.size() ; i++){
        if(s1[i] != s2[i]){
            return false;
        }
    }
    return true;
}

bool checkInclusion1(string s1, string s2) {
    int len1 = s1.length();
    int len2 = s2.length();

    vector<int> s1map(26);

    for(int i = 0; i< len1; i++){
        s1map[s1[i] - 'a']++;
    }

    for(int i = 0; i<= len2 -len1 ; i++){
        vector<int> s2map(26);
        for(int j = 0; j< len1; j++){
            s2map[s2[j+i] - 'a']++;
        }

        if(match(s1map, s2map)){
            return true;
        }
    }

    return false;

}

// Optimised
void printVec(vector<int>& vec){
    for(int i = 0; i< vec.size(); i++){
        cout << vec[i] << " " ;
    }

    cout << endl;
}

bool checkInclusion(string s1, string s2) {
    int len1 = s1.length();
    int len2 = s2.length();

    if(len2 < len1){
        return false;
    }

    vector<int> m1(26);
    vector<int> m2(26);

    // Fill up both the maps from both the strings till len1 size only
    for(int i = 0; i< len1; i++){
        m1[s1[i] - 'a']++;
        m2[s2[i] - 'a']++;
    }

    printVec(m1);
    printVec(m2);

    // Compare the maps now, if they are equal then it means a permutation does exist
    if(m1 == m2) {
        return true;
    }

    // Now Fill up the maps from the rest of the characters of s2
    for(int i = len1; i< len2; i++){

        m2[s2[i - len1] - 'a']--;
        m2[s2[i] - 'a']++;
        cout << i << endl;
        printVec(m1);
        printVec(m2);

        if(m1 == m2){
            return true;
        }
    }

    return false;
}






// Time Limit Exceeded
bool matches(map<char, int> s1, map<char, int> s2){
    if(s1.size() != s2.size()){
        cout << "Mismatch Size" << endl;
        return false;
    }

    for(auto &item : s1){
        cout << item.first << item.second <<  endl;
        if(s2[item.first] != s1[item.first])
            return false;
    }

    return true;
}

// Using Maps
bool checkInclusion2(string s1, string s2) {
    int len1 = s1.length();
    int len2 = s2.length();
    map<char, int> s1map;

    for(int i = 0; i< len1; i++){
        s1map[s1[i]]++;
    }

    for(int i = 0; i<= len2 -len1 ; i++){
        map<char, int> s2map;
        for(int j = 0; j< len1; j++){
            s2map[s2[j+i]]++;
        }

        if(matches(s1map, s2map)){
            return true;
        }
    }

    return false;
}