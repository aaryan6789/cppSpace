#include "_string.h"
#include <unordered_map>
#include <vector>

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    vector<int> letters(26);
    for (int i = 0; i < s.size(); i++){
        letters[s[i]-'a']++;
        letters[t[i]-'a']--;
    }
    for (int i = 0; i < 26; i++){
        if (letters[i] != 0) return false;
    }

    return true;
}


bool isAnagram2(string s, string t) {
    int slen = s.size();
    int tlen = t.size();

    if(slen != tlen){
        return false;
    }

    unordered_map<char, int> map;
    for(int i = 0; i< slen; i++){
        map[s[i]]++;
        map[t[i]]--;
    }

    for(auto& item : map){
        if(item.second != 0){
            return false;
        }
    }

    return true;

}