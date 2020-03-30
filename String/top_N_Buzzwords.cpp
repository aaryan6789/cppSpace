#include "_string.h"
/** Amazon | OA 2019 | Top N Buzzwords
 * You work on a team whose job is to understand the most sought after toys for 
 * the holiday season. 
 * 
 * A teammate of yours has built a webcrawler that extracts a list of quotes 
 * about toys from different articles. 
 * You need to take these quotes and identify which toys are mentioned most 
 * frequently. 
 * 
 * Write an algorithm that identifies the top N toys out of a list of quotes 
 * and list of toys. Your algorithm should output the top N toys mentioned most 
 * frequently in the quotes.

Input:
The input to the function/method consists of five arguments:

- numToys, an integer representing the number of toys
- topToys, an integer representing the number of top toys your algorithm needs to return;
- toys, a list of strings representing the toys,
- numQuotes, an integer representing the number of quotes about toys;
- quotes, a list of strings that consists of space-sperated words representing articles about toys

Output:
Return a list of strings of the most popular N toys in order of most to least frequently mentioned

Note:
The comparison of strings is case-insensitive. 
If the value of topToys is more than the number of toys, 
return the names of only the toys mentioned in the quotes. 

If toys are mentioned an equal number of times in quotes, sort alphabetically.

TWIST:
If the toys freq are the same then sort them as per their appearence in the num 
of Quotes.

Example 1:
Input:
numToys = 6
topToys = 2
toys = ["elmo", "elsa", "legos", "drone", "tablet", "warcraft"]
numQuotes = 6
quotes = [
"Elmo is the hottest of the season! Elmo will be on every kid's wishlist!",
"The new Elmo dolls are super high quality",
"Expect the Elsa dolls to be very popular this year, Elsa!",
"Elsa and Elmo are the toys I'll be buying for my kids, Elsa is good",
"For parents of older kids, look into buying them a drone",
"Warcraft is slowly rising in popularity ahead of the holiday season"
];

Output:
["elmo", "elsa"]

Explanation:
elmo - 4
elsa - 4
"elmo" should be placed before "elsa" in the result because "elmo" appears in 3 
different quotes and "elsa" appears in 2 different quotes.
 */

#include <sstream>
#include <algorithm>
#include <cctype>
using namespace std;

void convertToLower(vector<string>& quotes){

	for(int i = 0; i < quotes.size(); i++){
		for(int j = 0; j < quotes[i].size(); j++){
			if(isalpha(quotes[i][j])){
				// cout << quotes[j][i];
            	quotes[i][j] = tolower(quotes[i][j]);
			}
			else{
				// continue;
				quotes[i][j] = ' ';
			}
		}
	}
}
#include <queue>
using svi = pair<string, vector<int>>;
struct comp{
	bool operator()(const svi& lhs, const svi& rhs ){
		if(lhs.second[0] == rhs.second[0])
			return lhs.second[1] < rhs.second[1];
		else
			return lhs.second[0] < rhs.second[0];
	}
};

vector<string> topNBuzzwords(int numToys, int topToys, vector<string>& toys,
							 vector<string> quotes, int numQuotes){
	
	convertToLower(quotes);
	convertToLower(toys);
	for(auto quote : quotes){
		cout << quote << endl;
	}

	string word;
	// map [key = String : Value = Freq , FreqQuotes]
	unordered_map<string, vector<int>> mapFreq;
	// unordered_map<string, int> mapQuote;
	unordered_set<string> setQuote;
	

	for(auto buzz : toys){
		mapFreq[buzz] = {0, 0};
	}

	// Print the buzz Words
	for(auto kv : mapFreq){
		cout << kv.first << "  " << kv.second[0] << " " << kv.second[1] << endl;
	}

	for(auto& quote : quotes){
		stringstream ss(quote);

		while(ss >> word){
			// Get the Unique set of words
			setQuote.insert(word);
			if(mapFreq.find(word) != mapFreq.end()){
				mapFreq[word][0]++;
			}
		}

		// Increment the Freq Of Quotes for the word
		for(auto& word : setQuote){
			if(mapFreq.find(word) != mapFreq.end()){
				mapFreq[word][1]++;
			}
		}

		// for( auto words : setQuote){
		// 	cout << words << " ";
		// }

		setQuote.clear();
		// cout << endl;
	}

	// Print the buzz Words
	for(auto kv : mapFreq){
		cout << kv.first << "  " << kv.second[0] << " " << kv.second[1] << endl;
	}


	priority_queue<svi, vector<svi>, comp> maxHeap;

	for(auto kv : mapFreq){
		maxHeap.push({kv.first, kv.second});
	}

	vector<string> result;
	while(topToys>0){
		cout << maxHeap.top().first << endl;
		result.push_back(maxHeap.top().first);
		maxHeap.pop();
		topToys--;
	}

	return result;
}

void testTopNBuzz(){
	int numToys = 6;
	int topToys = 2;
	vector<string> toys = {"elmo", "elsa", "legos", "drone", "tablet", "warcraft"};
	int numQuotes = 6;
	vector<string> quotes = {
		"tablet Elmo is the hottest of the season! Elmo will be on every kid's wishlist!",
		"tablet The new Elmo dolls are super high quality",
		"tablet Expect the Elsa dolls to be very popular this year, Elsa!",
		"Elsa and Elmo are the toys I'll be buying for my kids, Elsa is good",
		"tablet For parents of older kids, look into buying them a drone",
		"Warcraft Elmo is slowly rising in popularity ahead of the holiday season"
	};

	topNBuzzwords(numToys, topToys, toys, quotes, numQuotes);
}