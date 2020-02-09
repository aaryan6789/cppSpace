#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <stack>

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


unordered_set<string> kSubstring(string s, int k);

vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord);
void testTopNBuzz();