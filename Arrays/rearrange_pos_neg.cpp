/* rearrange_pos_neg.c | Created on: Mar 25, 2018 | Author: hsahu */

#include "_array.h"
#include <algorithm>
/**
 * Rearrange Positive and Negative values in an array alternatively
 * 1. Partition the array around a value. Lets pick 0 for this case.
 * 2. Now the array that we have is partitioned into +ve and -ve values
 * 3. Pick a negative and positive number and swap them.
 * 4. Move negative by 1 and positive by 2.
 */
void regarrange_pos_neg(vector<int>& A) {
	int pi = -1;
    int size = A.size();
	//pivot = 0

	for(int j = 0; j<size; j++){
		if(A[j] < 0){
			pi++;
			std::swap(A[j], A[pi]);
		}
	}

	// Now the Array has been partitioned
	int neg = 0;	// Index of the 1st negative number
	int pos = pi+1;	// Index of the 1st Positive number

	while (neg<pos && pos<size && A[neg] < 0){		// <--- Pay attention here
		std::swap(A[neg], A[pos]);
		pos = pos+1;
		neg = neg+2;
	}
}