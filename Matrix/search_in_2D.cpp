#include "_matrix.h"
using namespace std;

/** Search a 2D Matrix | 74 LEETCODE M | https://leetcode.com/problems/search-a-2d-matrix/
 * Write an efficient algorithm that searches for a value in an m x n matrix. 
 * This matrix has the following properties:
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 * 
 * Example 1:
 * Input:
 * matrix = [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 * target = 3
 * Output: true
 * 
 * Example 2:
 * Input:
 * matrix = [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 * target = 13
 * Output: false
 */

/**
 * Binary search in a 2D matrix.
 */
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int R = matrix.size();
    if (R == 0) return false;
    int C = matrix[0].size();
    
    int left = 0;
    int right = R * C - 1;
    int mid;
    while( left <= right){
        mid = (left + right) / 2;
        int r = mid / C;
        int c = mid % C;
        
        if( matrix[r][c] == target){
            return true;
        }
        else if( target < matrix[r][c]){
            right = mid -1;
        }
        else{
            left = mid + 1;
        }
    }
    
    return false;
}
