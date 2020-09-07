
#include <algorithm>
#include <iostream>
#include "_array.h"
// Search a target element in a sorted and rotated array.

// Example:
//Input  : arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
//         key = 3
//Output : Found at index 8

/* Algorithm:
 * 1) Find out pivot point and divide the array in two sub-arrays.
 * 2) Now call binary search for one of the two sub-arrays.
 *    (a) If target element is greater than 0th element then
             search in left array
      (b) Else Search in right array

  3) If element is found in selected sub-array then return index
     Else return -1.

NOTE: The main idea for finding pivot is �
		for a sorted (in increasing order) and pivoted array,
		pivot element is the only element for which next element
		to it is smaller than it.
 */

int findPivot(vector<int> A, int start, int end){
	// Base Case
	if(start > end)
		return -1;

	// Base Case with only 1 element in the array
	if(start == end)
		return start;

	// Get mid element
	int mid = start + (end-start)/2;

	if(A[mid] > A[mid+1] && mid<end)
		return mid;

	if(A[mid-1]> A[mid] && mid > start)
		return (mid-1);

	if(A[start] >= A[mid])
		return findPivot(A, start, mid-1);
	else
		return findPivot(A, mid+1, end);
}

int find_Pivot_Iterative(vector<int> nums) {
	int left = 0;
	int right = nums.size() -1;

    if (nums[left] < nums[right])
		return 0;

    while (left <= right) {
		int pivot = (left + right) / 2;
		if (nums[pivot] > nums[pivot + 1])
			return pivot + 1;
		else {
			if (nums[pivot] < nums[left])
				right = pivot - 1;
			else
				left = pivot + 1;
		}
    }
    return 0;
}


int binarySearchSortedRotated(vector<int> A, int key){
	int size = A.size();
	int pivot = findPivot(A, 0, size-1);
	cout << "pivot " << pivot << "key " << key << endl;

	// If we couldnt find the pivot then the array is not rotated at all.
	if(pivot == -1){
		return std::binary_search(A.begin(), A.end(), key);
	}

	if(A[pivot] == key){
		return pivot;
	}

	if(A[0] <= key){
		return std::binary_search(A.begin(), (A.end()-pivot-1), key);
	}
	else{
		return std::binary_search(A.begin()+pivot+1, A.end(), key);
	}
}

/*
1) Find middle point mid = (l + h)/2
2) If key is present at middle point, return mid.
3) Else If arr[l..mid] is sorted
    a) If key to be searched lies in range from arr[l] to arr[mid],
       	   	recur for arr[l..mid].
    b) Else
    		recur for arr[mid+1..r]
4) Else (arr[mid+1..r] must be sorted)
    a) If key to be searched lies in range from arr[mid+1] to arr[r],
     	 	 recur for arr[mid+1..r].
    b) Else
    		recur for arr[l..mid]

 */

// Returns index of key in arr[l..h] if
// key is present, otherwise returns -1
int search(int arr[], int l, int h, int key)
{
    if (l > h) return -1;

    int mid = (l+h)/2;
    if (arr[mid] == key)
    	return mid;

    /* If arr[l...mid] is sorted */
    if (arr[l] <= arr[mid]) {

        /* As this subarray is sorted, we can quickly
        check if key lies in half or other half */

    	if (key >= arr[l] && key <= arr[mid])
    		return search(arr, l, mid-1, key);
    	else
    		return search(arr, mid+1, h, key);
    }

    /* If arr[l..mid] is not sorted, then arr[mid... r]
    must be sorted*/
    if (key >= arr[mid] && key <= arr[h])
        return search(arr, mid+1, h, key);
    else
    	return search(arr, l, mid-1, key);
}
