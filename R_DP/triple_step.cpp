#include "_r_dp.h"

/**
 * count_ways - Count the number of ways to reach the nth step
 * Recursive Solution
 * Base Case => if n = 1 or 0 then only 1 way
 * Recursive Case => if n>1 then recursively call the count_ways
 */
int count_ways(int n) {
	// Base Case or End Case
	int count_total;
	if (n<0){
		return 0;
	}
	else if ((n==0) || (n==1)){
		return 1;
	}
	else{
		// Recursive Case
		//printf("Count_ways = %d\n", (count_ways(n-1) + count_ways(n-2) + count_ways(n-3)));
		count_total = (count_ways(n-1) + count_ways(n-2) + count_ways(n-3));
		//return (count_ways(n-1) + count_ways(n-2) + count_ways(n-3));
	}

	//printf("Count Ways = %d\n", count_total);
	return count_total;
}

/** DP - TABULATION
 * count_ways_dp - Count the number of ways to reach to the nth step by DP
 * Tabulation: Caching iteratively
 * Cache the results of the Subproblems
 * Subproblems being the the ways to reach to the (n-i)th step.
 */
int count_ways_dp(int n){
	int count_total;
	vector<int> cache(n+1, -1);

	// Base Cases
	cache[0] = 1;
	cache[1] = 1;
	cache[2] = 2;

	// Go for the rest of the stairs and calculate the total ways
	for (int i = 3; i<=n; i++){
		cache[i] = cache[i-1] + cache[i-2] + cache[i-3];
	}

	count_total = cache[n];
	return count_total;
}


int count_ways_dp_memorization(int n, int memo[]);
/** DP - MEMORIZATION
 *
 */
int count_ways_wrapper(int n){
	int memo[n+1];

	for (int i=0; i<=n+1; i++) {
		memo[i]= -1;// set value -1 to all the array index
	}

	return count_ways_dp_memorization(n, memo);
}

int count_ways_dp_memorization(int n, int memo[]){

	if (n<0){
		return 0;
	}
	else if(n == 0){
		return 1;
	}
	else if (memo[n] > -1){
		return memo[n];
	}
	else {
		memo[n] = 	count_ways_dp_memorization(n-1, memo) +
					count_ways_dp_memorization(n-2, memo) +
					count_ways_dp_memorization(n-3, memo);
		return memo[n];
	}
}
