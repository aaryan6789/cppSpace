#include "_array.h"
#include <cmath>
/**
 * LeetCode E
 * Two elements whose sum is closest to zero
 *
 * An Array of integers is given, both +ve and -ve.
 * You need to find the two elements such that their sum is closest to zero.
 * For the below array, program should print -80 and 85.
 */

using namespace std;

/**
 * Algorithm 1 : 2 Pointer Solution:
 * Using Sorting and Searching (STL)
 * - Sort the array
 * - left = 0 right = end
 * - Get the sum and compare against it.
 */
void sum_close_to_zero(vector<int>& A){
    // Sort the array
    std::sort(A.begin(), A.end());
    printArray(A);

    int minSum = INT8_MAX;

    int min_left, min_right;
	int l = 0;
	int r = A.size();

    while (l < r){
        int sum = A[l] + A[r];

        cout << "Sum = " << sum << " abs(sum) = " << abs(sum) << " minSum = " << minSum << endl;

		if(abs(sum) <= abs(minSum)){				//<----- Pay attention here
			cout << "l = " << l  << " r = " << r << endl;
			minSum = sum;
			min_left = l;
			min_right = r;
		}

		if(sum<0){
			l++;
		}
		else{
			r--;
		}
	}
}