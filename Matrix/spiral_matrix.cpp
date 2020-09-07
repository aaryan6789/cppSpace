#include "_matrix.h"

/** SPIRAL MATRIX | LEETCODE M | 54 | https://leetcode.com/problems/spiral-matrix/
 * 
 * Given a matrix of m x n elements (m rows, n columns), return all elements
 * of the matrix in spiral order.
 * 
 * Example 1:
 * Input:
 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * Example 2:
 * Input:
 * [
 *   [1, 2, 3, 4],
 *   [5, 6, 7, 8],
 *   [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 */

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = m ? matrix[0].size() : 0;
    
    int u = 0;          // Up
    int d = m - 1;      // Down
    int l = 0;          // Left
    int r = n - 1;      // Right
    int p = 0;          // Position

    vector<int> order(m * n);       // OutPut Vector

    while (u <= d && l <= r) {
        for (int col = l; col <= r; col++) {
            order[p++] = matrix[u][col];
        }
        if (++u > d) {
            break;
        }

        for (int row = u; row <= d; row++) {
            order[p++] = matrix[row][r];
        }
        if (--r < l) {
            break;
        }
        
        for (int col = r; col >= l; col--) {
            order[p++] = matrix[d][col];
        }
        if (--d < u) {
            break;
        }
        
        for (int row = d; row >= u; row--) {
            order[p++] = matrix[row][l];
        }
        if (l++ > r) {
            break;
        }
    }
    return order;
}