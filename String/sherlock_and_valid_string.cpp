#include "_string.h"
bool allSame(vector<int>& map){
    int same = 0;
    for(int i = 0; i<map.size(); i++){
        if(map[i] > 0){
            same = map[i];
            break;
        }
    }

    for(int i = 0 ; i< map.size(); i++){
        if(map[i] > 0 && map[i] != same){
            return false;
        }
    }
    return true;
}

// Complete the isValid function below.
string isValid(string s) {
    // Make a Frequency map of the given string
    vector<int> map(26);
    string yes = "YES";
    string no = "NO";

    for(int i = 0; i< s.length(); i++){
        map[s[i] - 'a']++;
    }

    // Case 1 
    // All have same Frequency
    if(allSame(map)){
        return yes;
    }
    // Case 2 
    // Only 1 Char has a Frequency count 1 less then other chars
    for(char c = 'a' ; c <= 'z'; c++){
        if(map[c - 'a'] > 0){       // Reduce freq by 1 and check if the map has same
            map[c - 'a']--;

            if(allSame(map))
                return yes;
            
            map[c - 'a']++;
        }
    }

    // Case 3
    // 1 character has frequnecy more than other chars
    return no;



    // unordered_map<int, int> map2;
    // for(auto kv : map){
    //     // cout << kv.second << " " ;
    //     map2[kv.second]++;
    // }

    // cout << map2.size() << endl;
    // if(map2.size() > 2){
    //     // cout << "Map size bigger then 2" << endl;
    //     return no;
    // }
    // else if(map2.size() == 2){
    //     if(abs(map2.begin()->first - (++map2.begin())->first) == 1){
    //         // cout << "Diff is just 1" << endl;
    //         return yes;
    //     }
    //     if(abs(map2.begin()->second - (++map2.begin())->second) == 1){
    //         // cout << "Diff is just 1" << endl;
    //         return yes;
    //     }
    //     else{
    //         return no;
    //     }
    // }
    // else if(map2.size() == 1){
    //     return yes;
    // }
    
    // return no;

}