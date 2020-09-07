
/** PRODUCT SUGGESTIONS | AMAZON OA | LEETCODE M 
 * Given an array of strings products and a string searchWord. 
 * We want to design a system that suggests at most three product names from 
 * products after each character of searchWord is typed. 
 * Suggested products should have common prefix with the searchWord. 
 * If there are more than three products with a common prefix return the three 
 * lexicographically minimums products.
 * 
 * Return list of lists of the suggested products after each character of searchWord is typed. 
 * 
 * Example 1:
 * Input:  products = ["mobile", "mouse", "moneypot", "monitor", "mousepad"], 
 *         searchWord = "mouse"
 * Output: [
 *             ["mobile","moneypot","monitor"],
 *             ["mobile","moneypot","monitor"],
 *             ["mouse","mousepad"],
 *             ["mouse","mousepad"],
 *             ["mouse","mousepad"]
 *         ]
 * 
 *          [
 *          m    : ["mobile","moneypot","monitor"],
 *          mo   : ["mobile","moneypot","monitor"],
 *          mou  : ["mouse","mousepad"],
 *          mous : ["mouse","mousepad"],
 *          mouse: ["mouse","mousepad"]
 *         ]
 * 
 * Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]
 * After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
 * After typing mou, mous and mouse the system suggests ["mouse","mousepad"]
 * 
 * Example 2:
 * Input: products = ["havana"], 
 *        searchWord = "havana"
 * Output: [
 *             ["havana"],
 *             ["havana"],
 *             ["havana"],
 *             ["havana"],
 *             ["havana"],
 *             ["havana"]
 *         ]
 * 
 * Example 3:
 * Input:  products = ["bags","baggage","banner","box","cloths"], 
 *         searchWord = "bags"
 * Output: [
 *             ["baggage","bags","banner"],
 *             ["baggage","bags","banner"],
 *             ["baggage","bags"],
 *             ["bags"]
 *         ]
 * 
 * Example 4:
 * Input:  products = ["havana"], 
 *         searchWord = "tatiana"
 * Output: [
 *             [],
 *             [],
 *             [],
 *             [],
 *             [],
 *             [],
 *             []
 *         ]
 * 
 * Constraints:
 * 1. 1 <= products.length <= 1000
 * 2. There are no repeated elements in products.
 * 3. 1 <= Σ products[i].length <= 2 * 10^4
 * 4. All characters of products[i] are lower-case English letters.
 * 5. 1 <= searchWord.length <= 1000
 * 6. All characters of searchWord are lower-case English letters.
 */
#include "_string.h"

/**
 * Explanation
For any two word w1 and w2 from all words,
If word w1 is prefix of w2,
w1 and w2 must be neighbours in the sorted words A.

The same, we can binary search the position of each prefix of search word,
and check if the next 3 words is valid.
 */

// Sort all products. 
// Then do binary search for substrings of increasing size, taking up to three words.
// Optimized Solution
// If you are concerned about substr creating strings in the loop, 
// we can build our string as we go and use the compare function. 


    
vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    sort(products.begin(),products.end());
    vector<vector<string>> vec(searchWord.size());
    
    // Go over the Products Words
    for(int i=0; i<products.size(); i++){
        
        // Go over each word and search for the matching words
        for(int k=0; k<searchWord.size(); k++){
            if(searchWord[k] == products[i][k]){
                cout << "K " << k << " matches " << products[i][k] << endl;
                // cout << "Product String " << products[i]<< endl;
                if(vec[k].size()<3){
                    cout << k << " pushing " << products[i] << endl;
                    vec[k].push_back(products[i]);
                }
            }
            else
                break;
        }
    }

    return vec;
}



vector<vector<string>> suggestedProducts2(vector<string>& products, string searchWord) {
    sort(products.begin(), products.end());
    vector<vector<string>> result;

    for (int l = 0; l < searchWord.size(); ++ l) {
        cout << "Search Word " << searchWord.substr(0, l+1) << endl;
        auto start = lower_bound(products.begin(), products.end(), searchWord.substr(0, l+1));
        auto end = lower_bound(start, min(start+3, products.end()), searchWord.substr(0, l) + (char)(searchWord[l]+1));
        result.push_back(vector<string>(start, end));
    }
    return result;		         
}


vector<vector<string>> suggestedProducts3(vector<string>& products, string searchWord) {
    // Lexicographically Sort the Words first
    sort(products.begin(), products.end());

    vector<vector<string>> res;
    string pat = "";
    auto it = products.begin();
    for(char c : searchWord) {
        pat += c;
        vector<string> suggested;
        it = lower_bound(it, products.end(), pat);
        
        for(int i=0; i<3; i++) {
            if(it+i == products.end()) 
                break;
            
            string& n = *(it+i);
            
            if (pat != n.substr(0, pat.size())) 
                break;
            
            suggested.push_back(n);
        
        }
        res.push_back(suggested);
    }

    return res;
}


vector<vector<string>> suggestedProducts4(vector<string>& A, string searchWord) {
    auto it = A.begin();
    sort(it, A.end());
    vector<vector<string>> res;
    string cur = "";
    for (char c : searchWord) {
        cur += c;
        vector<string> suggested;
        it = lower_bound(it, A.end(), cur);
        for (int i = 0; i < 3 && it + i != A.end(); i++) {
            string& s = *(it + i);
            if (s.find(cur)) break;
            suggested.push_back(s);
        }
        res.push_back(suggested);
    }
    return res;
}