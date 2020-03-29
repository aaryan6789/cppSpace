#include "_array.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


// Find K'th largest element in an array

// Method 1 : Using min-heap
// 1. Make a MinHeap of the 1st K elements in the array
// 2. Now after this compare the element with the top of the minHeap
//    If the element is greater then the TOP then it is inserted in the heap
//	  Else, keep going
// Time Complexity = Make Heap = O(k)
//					 Heapify = (n-k) logK
int FindKthLargest2(vector<int> const &A, int k){
	// create an min-heap using std::priority_queue and insert
	// first k elements of the array into the heap
	// std::greater is used as the comparison function for min-heap
	priority_queue<int, vector<int>, std::greater<int>> minHeap(A.begin(), A.begin() + k);

	// do for remaining array elements
	for (int i = k; i < A.size(); i++){
		// if current element is more than the root of the heap
		if (A[i] > minHeap.top()){
			// replace root with the current element
			minHeap.pop();
			minHeap.push(A[i]);
		}
	}

	// return the root of min-heap
	return minHeap.top();
}

// Method 2 = Using MaxHeap
// 1. Create a Max Heap
// 2. Pop from the heap k times
// Return the top item.
// Time Complexity = O(n + Klogn)
int findKthLargest2(vector<int>& nums, int k) {
	priority_queue<int> maxHeap (nums.begin(), nums.end()); // create an max-heap using priority_queue from all elements of the vector

	// k = nums.size() - k + 1;
	int item;
	// pop from max-heap exactly (k-1) times
	while(k-- != 0){
		item = maxHeap.top();
		// cout << item << endl;
		maxHeap.pop();
	}

	return item;	// return the root of max-heap
}

int findKthLargest(vector<int>& nums, int k) {
	priority_queue<int, vector<int>, greater<int>> minHeap;
	for(int i=0; i<nums.size(); i++){
		minHeap.push(nums[i]);
		if(minHeap.size()>k)
			minHeap.pop();
	}
	return minHeap.top();
}

// Using Sorting
int findKthLargestSort(vector<int>& nums, int k) {
	if(nums.size() <k) return -1;
	int sz = nums.size();
	sort(nums.begin(),nums.end());
	return nums[sz-k];
	
}