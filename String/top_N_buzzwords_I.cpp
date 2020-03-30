#include "_string.h"
/*
OLD QUESTION
Find top N frequent words in the maximum number of quotes.
The input was a list of quotes and a list of buzzwords. 
The output should be top N buzzwords which are found in maximum quotes. 
The matching should be done in a case-insensitive way. 
The output words should be sorted alphabetically if two (or more) 
words are found in equal number of quotes.

For eg.
*Quotes:	{	"Football is a game, which I like!",
				"I go to the market and buy sweets from the market",
				"I love watching football matches from stall",
				"I opened a stall"
			}

*buzzWords-	{	"stall", "market", "football"}
*N=2
*result= "football", "stall"
*Explanation: 
"football","stall" come in 2 quotes whereas "market" only in one.
Also note that football has to be first as the result is sorted alphabetically 
if the count is same

public List findTopBuzzWords(List quotes,List buzzwords,int N)
The twist in the question is to make sure that we increase the count of each 
word only once in each quote. 
Of course, changing the buzzWords list to set is important to search with O(1) 
complexity.
*/
#include <sstream>
void convert(vector<string>& quotes){
	for(int j = 0; j < quotes.size(); j++){
		for(int i = 0; i < quotes[j].length(); i++){
            if(isalpha(quotes[i][j]))
            	quotes[j][i] = tolower(quotes[j][i]);
		}
	}
}

vector<string> getFrequent(vector<string>& quotes, vector<string>& buzzwords, int N){
	unordered_map<string, int> map;
	vector<string> result;
	
	//Convert each quote in the quote string to lowercase and remove special chars e.g "!"
	convert(quotes);
	
	for(auto quote: quotes){
		unordered_set<string> mystring;
		
		string word;
		stringstream ss(quote);
		
		while(ss >> word){
			mystring.insert(word);
		}
		
		for(auto buzz: buzzwords){
			if (mystring.find(buzz) != mystring.end()){
				map[buzz]++;
			}
		}
	}
	
	//Now gather N frequent
	for(auto p: map){
		if(p.second == N){
		    result.push_back(p.first);
		}
	}
	
	//Now sort Result on alphabetical order if identical frequemcies are found
	if(result.size() > 1){
		sort(result.begin(), result.end());
	}
	
	return result;
}

//Tester Function
void test(vector<string>& actual, vector<string>& expected){
	int exp_size = expected.size();
	int actual_size = actual.size();
	
	if(exp_size != actual_size) {
		cout << "Error 1: actual: "<< actual_size << ", expected : " << exp_size << endl;
		return;
	}
	
	while(exp_size){
		if(actual[exp_size - 1] != expected[exp_size - 1]){
			cout << " Actual[" << exp_size - 1 << "] :" << actual[exp_size - 1] << ", Expected [" << exp_size - 1 << "] is " << expected[exp_size - 1] << endl;
		}else{
			cout << "Expected and Actual match for buzzword " << actual[exp_size - 1] << endl;
		}
		exp_size--;
	}
}