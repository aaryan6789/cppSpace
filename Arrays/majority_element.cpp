#include "_array.h"
/*
 * majority_element
 * CTCI 6 17.10 | LeetCode Medium
 *
 * Given an array of size n, find the majority element.
 * The majority element is the element that appears more than (n/2) times.
 * You may assume that the array is non-empty and the majority element always exist in the array.
 * A majority element is that element which appears more then half the size of the array.
 */

/**
 * Algorithm 1 : Using HashMap
 * 1. Parse through the array and put it in the map (key, value) pair.
 *    If already present then increment its count.
 * 2. Parse through the Map and return the count maximum.
 *
 * Time Complexity = O(n)
 * Space Complexity = O(n)
 */

int majorityElement(vector<int>& A) {
    // Make a Hashmap
    unordered_map<int, int> map;
    int n = A.size();
    cout << "Size = " << n << endl;

    for(auto& item : A){
        map[item]++;
    }

    // Parse through the map and find the majority element
    cout << "Key " << "Val" << endl;
    for (auto& m : map){
        cout << m.first << " " << m.second << endl;
        if(m.second > (n/2)){
            cout << "Majority Element found = " << m.first << endl;
            return m.first;
        }
    }

    return -1;
}

/**
 * Algorithm 2 =  Using Sorting and returning
 * Time Complexity = O(nlogn)
 * Space = O(1)
 *
 * Given the fact that there is an element which is majority in the array
 */
int majorityElement2(vector<int>& A) {
    int n = A.size()/2;
    sort(A.begin(), A.end());

    return (A[n]);
}

/**
 * Algorithm 3 - Voting Algo
 *
 * printMajority (a[], size)
    1.  Find the candidate for majority
    2.  If candidate is majority. i.e., appears more than n/2 times.
           Print the candidate
    3.  Else
           Print "No Majority Element"

    Time Complexity: O(n)
    Auxiliary Space : O(1)
 */
int check_for_majority(vector<int>& A, int maj);

int majority_element(vector<int>& A){
	int majority = 0;
	int count = 0;
    int size = A.size();

	for(int i = 0; i< size; i++){
		// If count is 0, then set this element as the majority
		if(count == 0){
			majority = A[i];
			count = 1;
			continue;       // Go to the ext iteration of the loop, dont go further in the loop
		}
		// else if the current element is a majority element
		else {
			if (A[i] == majority)
				count++ ;
			else
				count-- ;
		}
	}

	int res = check_for_majority(A, majority);
	cout << "Majority element = " << res << endl;
	return res;
}

int check_for_majority(vector<int>& A, int maj){
	int count = 0;
    int size = A.size();

	for(int i = 0; i<size; i++){
		if(A[i] == maj){
			count++;
		}
	}

	if(count >= size/2)
		return maj;
	else
		return -1;

}

// Follow Up | Leetcode Easy
//Given an array nums sorted in non-decreasing order, and a number target, return True if and only if target is a majority element.
// A majority element is an element that appears more than N/2 times in an array of length N.

// Since Sorted Array
// Using Binary Search
bool isMajorityElement(vector<int>& nums, int target) {
    if (nums.size() == 1) {
        return nums[0] == target;
    }

    vector<int>::iterator it;

    it = lower_bound(nums.begin(), nums.end(), target);
    int low = it - nums.begin();

    it = upper_bound(nums.begin(), nums.end(), target);
    int high = it - nums.begin();

    return (high - low) * 2 > nums.size();
}