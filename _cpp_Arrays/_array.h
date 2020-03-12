#pragma once
#include <iostream>
#include <utility>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

template <typename T>
void printArray(const vector<T>& A){
    for(int i = 0 ; i< A.size() ; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

/// TWO POINTERS
vector<int> twoSum(vector<int>& nums, int target);
int maxArea(vector<int>& height);
int findPairs(vector<int>& nums, int k);
int findPairs2(vector<int>& nums, int k);
void sum_close_to_zero(vector<int>& A);

/// SORTING AND SEARCHING
int removeDuplicates(vector<int>& nums);
int majorityElement(vector<int>& A);
int majorityElement2(vector<int>& A);

/// Partition Based 
void regarrange_pos_neg(vector<int>& A);
void peaks_and_valleys(vector<int>& A);

/// SET
int singleNumberSet(vector<int>& nums);

/// SLIDING WINDOW
vector<int> kClosestElementToVal(vector<int>& A, int val);

/// SUB ARRAY Problems
bool checkZeroSubArray(vector<int>& A);
void printZeroSumSubArray(vector<int>& A);

/// HEAP based Problems
int FindKthLargest2(vector<int> const &A, int k);
vector<int> smallestK(vector<int>& nums, int k);

/// Array Modification
vector<int> productExceptSelf(vector<int>& nums);


/// Binary Search related

int binarySearchSortedRotated(vector<int> A, int key);


// template<typename T>
// vector<T> kClosestElementToVal(vector<T>& A, T val);
