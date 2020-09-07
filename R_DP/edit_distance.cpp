#include "_r_dp.h"
/**
 * Approach 1: Dynamic Programming
The idea would be to reduce the problem to simple ones. 
For example, there are two words, horse and ros and we want to compute an 
edit distance D for them. 
One could notice that it seems to be more simple for short words and so it would 
be logical to relate an edit distance D[n][m] with the lengths n and m of input words.

Let's go further and introduce an edit distance D[i][j] which is an 
edit distance between the first i characters of word1 and the first j characters of word2.

edit_distance

It turns out that one could compute D[i][j], knowing D[i - 1][j], D[i][j - 1] and D[i - 1][j - 1].

There is just one more character to add into one or both strings and the formula is quite obvious.

If the last character is the same, i.e. word1[i] = word2[j] then

D[i][j]=1+min(D[i−1][j],D[i][j−1],D[i−1][j−1]−1)

and if not, i.e. word1[i] != word2[j] we have to take into account the replacement of the last character during the conversion.

D[i][j]=1+min(D[i−1][j],D[i][j−1],D[i−1][j−1])

So each step of the computation would be done based on the previous computation, as follows:

compute

The obvious base case is an edit distance between the empty string and non-empty string that means D[i][0] = i and D[0][j] = j.

Now we have everything to actually proceed to the computations 
*/

int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    
    int cache[m+1][n+1];
    
    cache[0][0] = 0;
    
    // Fill in 1st Col
    for(int i = 1; i<=m; i++){
        cache[i][0] = i;
    }
    
    // Fill in 1 Row
    for(int j = 1; j<=n; j++){
        cache[0][j] = j;
    }
    
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(word1[i-1] == word2[j-1]){
                cache[i][j] = cache[i-1][j-1];
            }
            else {
                cache[i][j] = 1 + min(min(cache[i-1][j-1], cache[i-1][j]) , cache[i][j-1] ) ;
            }   
        }
    }
        
    
    return cache[m][n];
}