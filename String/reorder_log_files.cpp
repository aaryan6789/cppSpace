#include "_string.h"

/**
 * LeetCode E | Amazon
 * You have an array of logs.  
 * Each log is a space delimited string of words.
 * For each log, the first word in each log is an alphanumeric identifier.  
 * Then, either:
 * 
 * > Each word after the identifier will consist only of lowercase letters, or;
 * > Each word after the identifier will consist only of digits.

 * We will call these two varieties of logs letter-logs and digit-logs.  
 * It is guaranteed that each log has at least one word after its identifier.
 * 
 * Reorder the logs so that all of the letter-logs come before any digit-log.  
 * The letter-logs are ordered lexicographically ignoring identifier, 
 * with the identifier used in case of ties.  
 * The digit-logs should be put in their original order.
 * 
 * Return the final order of the logs.
 * 
 * Example 1:
 * Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
 * Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
 *  
 * 
 * Constraints:
 * 
 * 0 <= logs.length <= 100
 * 3 <= logs[i].length <= 100
 * logs[i] is guaranteed to have an identifier, and a word after the identifier.
 */

static bool myCompare(pair<string, string>& p1, pair<string, string>& p2){
    if(p1.second == p2.second){
        if(p1.first > p2.first)
            return false;
        else
            return true;
    }
    else {
        if(p1.second > p2.second)
            return false;
        else
            return true;
    }
}

vector<string> reorderLogFiles(vector<string>& logs) {
    vector<string> digitLogs;
    vector<pair<string, string>> letterLogs;
    
    // Get the Strings from the Logs
    for(const auto& str : logs){
        int pos = str.find(" ");    // Find the space digit
        
        // If the Following char is a Digit then push it ot digitLogs else to letter Logs
        if(isdigit(str[pos+1])){
            digitLogs.push_back(str);
        }
        else{
            letterLogs.push_back(make_pair(str.substr(0, pos), str.substr(pos+1)));
        }
    }
    
    sort(letterLogs.begin(), letterLogs.end(), myCompare);
    vector<string> result;
    for(const auto& str : letterLogs){
        string res = str.first + " " + str.second;
        result.push_back(res);
    }
    
    for(const auto& str : digitLogs)
        result.push_back(str);
    
    return result;
}
