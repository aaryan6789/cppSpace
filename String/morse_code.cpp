#include "_string.h"
/**
 * Leetcode Easy | Set Data Structure
 * International Morse Code defines a standard encoding where each letter is
 *  mapped to a series of dots and dashes, as follows:
 *  "a" maps to ".-", "b" maps to "-...", "c" maps to "-.-.", and so on.
 *
 * For convenience, the full table for the 26 letters of the English alphabet is
 * given below:
 *
 * [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--",
 * "-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
 *
 * Now, given a list of words, each word can be written as a concatenation of
 * the Morse code of each letter.
 * For example, "cba" can be written as "-.-..--...",
 * (which is the concatenation "-.-." + "-..." + ".-").
 * We'll call such a concatenation, the transformation of a word.
 *
 * Return the number of different transformations among all words we have.
 *
 * Example:
 * Input: words = ["gin", "zen", "gig", "msg"]
 * Output: 2
 * Explanation:
 * The transformation of each word is:
 * "gin" -> "--...-."
 * "zen" -> "--...-."
 * "gig" -> "--...--."
 * "msg" -> "--...--."
 *
 * There are 2 different transformations, "--...-." and "--...--.".
 *
 * Note:
 * 1. The length of words will be at most 100.
 * 2. Each words[i] will have length in range [1, 12].
 * 3. words[i] will only consist of lowercase letters.
 */

#include <unordered_set>
int uniqueMorseRepresentations(vector<string>& words) {
	// Get the vector of strings for the morse codes
	vector<string> codes = {".-","-...","-.-.","-..",".","..-.","--.","....",
	"..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-",
	"...-",".--","-..-","-.--","--.."};

	// Insert the morse code into a set for keeping only the unique values
	unordered_set<string> set;
	string morse;
	for(auto& word : words){
		morse = "";
		for(const char c : word){
			morse += codes[c - 'a'];
		}
		set.insert(morse);
	}
	return set.size();
}

int uniqueMorseRepresentations1(vector<string>& words) {
	const static string code[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
	unordered_set<string> set;

	for (auto word : words) {
		string morse = "";

		for (auto ch : word)
			morse += code[ch - 'a'];

		set.insert(morse);
	}

	return set.size();
}

#include <unordered_map>
int uniqueMorseRepresentations2(vector<string>& words) {
	const static string code[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };

	unordered_map<char, string> map;

	char ch = 'a';
	for (const auto& item : code){
		map[ch++] = item;
	}

	for(const auto& item : map){
		cout << item.first << " " << item.second << endl;
	}

	unordered_set<string> set;
	string morse;
	for (auto word : words){
		morse = "";
		for (const char& ch : word){
			morse += map[ch];
		}
		cout << morse;
		set.insert(morse);
	}

	cout << set.size() << endl;

	return 0;
}
