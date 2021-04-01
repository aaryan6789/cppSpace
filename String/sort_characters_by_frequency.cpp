/**
 * 451. Sort Characters By Frequency
 * Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 */


// Time Complexity: O(n)
// O(26log(n)) = O(log(n)) For Construction and extraction from heap
// O(n) For storing the frequency in hashmap.

string frequencySort(string s) {
    unordered_map<char,int> freq;           //for frequency of characters
    priority_queue<pair<int,char>> maxheap; //maxheap according to frequency of characters
    for(char c: s)
        freq[c]++;
    for(auto it: freq)
        maxheap.push({it.second,it.first}); //heap will be constructed on the basis of frequency
    s="";   
    while(!maxheap.empty()){
        s+=string(maxheap.top().first,maxheap.top().second); //frequency times the character
        maxheap.pop();
    }
    return s;
}