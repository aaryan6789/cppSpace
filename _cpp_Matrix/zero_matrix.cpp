/**
 * CTCI | Leetcode M : https://leetcode.com/problems/set-matrix-zeroes/
 * Zero Matrix / Set Zero Matrix
 * Write an algorithm such that if an element in an MxN matrix is 0, its entire
 * row and column are set to 0.
 *
 * Example 1:
 *
 * Input:
 * [
 *   [1,1,1],
 *   [1,0,1],
 *   [1,1,1]
 * ]
 * Output:
 * [
 *   [1,0,1],
 *   [0,0,0],
 *   [1,0,1]
 * ]
 *
 * Example 2:
 *
 * Input:
 * [
 *   [0,1,2,0],
 *   [3,4,5,2],
 *   [1,3,1,5]
 * ]
 * Output:
 * [
 *   [0,0,0,0],
 *   [0,4,5,0],
 *   [0,3,1,0]
 * ]
 *
 * Follow up:
 * - A straight forward solution using O(mn) space is probably a bad idea.
 * - A simple improvement uses O(m + n) space, but still not the best solution.
 * - Could you devise a constant space solution?
 *
 */

#include "_matrix.h"
using namespace std;

/**
 * Method - (A Space Optimized Version of Method 1)
 * This method uses the first row and first column of the input matrix.
 * So what we do is:
 * first take care of first row and column and store the info about these two in
 * two flag variables rowFlag and colFlag.
 *
 * Once we have this info, we can use first row and first column as auxiliary arrays
 *  and apply method 1 for submatrix (matrix excluding first row and first column)
 *   of size (M-1)*(N-1).
 *
 * 1) Scan the first row and set a variable rowFlag to indicate whether we need to set all 1s in first row or not.
 * 2) Scan the first column and set a variable colFlag to indicate whether we need to set all 1s in first column or not.
 * 3) Use first row and first column as the auxiliary arrays row[] and col[] respectively,
 *  consider the matrix as submatrix starting from second row and second column and apply method 1.
 * 4) Finally, using rowFlag and colFlag, update first row and first column if needed.
 *
 * Time Complexity: O(M*N)
 * Auxiliary Space: O(1)
 */

void setZeroes(vector<vector<int>>& matrix) {
    // variables to check if there are any 1 in first row and column
    bool row_flag = false;
    bool col_flag = false;

    int R = matrix.size();
    int C = matrix[0].size();

    // Update the first row and col flags if 0 is encountered
    for(int i = 0; i< R; i++){
        for(int j = 0; j< C; i++){
            if (i == 0 && matrix[i][j] == 0)        // If any 0 in first row
                row_flag = true;

            if (j == 0 && matrix[i][j] == 0)        // If any 0 in first column
                col_flag = true;

            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Modify the input matrix using the
    // first row and first column of Matrix
    for (int i = 1; i < R; i++) {
        for (int j = 1; j < C; j++) {

            if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // modify first row if there was any 1
    if (row_flag == true) {
        for (int i = 0; i < C; i++) {
            matrix[0][i] = 0;
        }
    }

    // modify first col if there was any 1
    if (col_flag == true) {
        for (int i = 0; i < R; i++) {
            matrix[i][0] = 0;
        }
    }
}