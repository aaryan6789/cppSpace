#include "_array.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


// Find K'th largest element in an array


// Using max-heap
int FindKthLargest(vector<int> const &A, int k){
	// create an max-heap using priority_queue from all elements of the vector
	priority_queue<int, vector<int>> pq(less<int>(), A);

	// pop from max-heap exactly (k-1) times
	while(--k) {
		pq.pop();
	}

	// return the root of max-heap
	return pq.top();
}

// Using min-heap
int FindKthLargest2(vector<int> const &A, int k){
	// create an min-heap using std::priority_queue and insert
	// first k elements of the array into the heap
	// std::greater is used as the comparison function for min-heap
	priority_queue<int, vector<int>, greater<int>> pq(A.begin(), A.begin() + k);

	// do for remaining array elements
	for (int i = k; i < A.size(); i++){
		// if current element is more than the root of the heap
		if (A[i] > pq.top()){
			// replace root with the current element
			pq.pop();
			pq.push(A[i]);
		}
	}

	// return the root of min-heap
	return pq.top();
}


int findKthLargest2(vector<int>& nums, int k) {
	priority_queue<int> maxHeap (nums.begin(), nums.end());

	// k = nums.size() - k + 1;
	int item;
	while(k-- != 0){
		item = maxHeap.top();
		// cout << item << endl;
		maxHeap.pop();
	}

	return item;;
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