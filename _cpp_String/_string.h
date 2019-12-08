#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>


using namespace std;

void is_unique(string s);

namespace first {
int firstUniqChar(string s);
}

int uniqueMorseRepresentations(vector<string>& words);
int uniqueMorseRepresentations1(vector<string>& words);
int uniqueMorseRepresentations2(vector<string>& words);



void pangram(string s);

void checkPermutation(string s1, string s2);

void permutation_palindrome(string& str);

int compress(vector<char>& chars);
void printRLE(string str);