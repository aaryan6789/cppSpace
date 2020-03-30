#include "_matrix.h"
/**
 * CTCI
 * Rotate Matrix:
 * Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes,
 * Write a method to rotate the image by 90 degrees. Can you do this in place?
 *
 * Examples :
Input
 1  2  3
 4  5  6
 7  8  9

Output:
 3  6  9
 2  5  8
 1  4  7

Input:
 1  2  3  4
 5  6  7  8
 9 10 11 12
13 14 15 16

Output:
 4  8 12 16
 3  7 11 15
 2  6 10 14
 1  5  9 13
*/

#include <vector>
#include <algorithm>
using namespace std;


// Anti Clock Wise Rotation :
// Transpose the Matrix --> Reverse Colums

// Clock Wise Rotation :
// Transpose the Matrix --> Reverse Rows

// Time complexity : O(n2)
// Space complexity : O(1) since we do a rotation in place.
void rotate(vector<vector<int>>& matrix) {
    int R = matrix.size();
    
    // Transpose the Matrix
    for(int i=0; i<R; i++)
        for(int j=0; j<i; j++)
            swap(matrix[i][j], matrix[j][i]);
    
    // Reverse the Rows
    for(int i=0; i<R; i++)
        reverse(matrix[i].begin(), matrix[i].end());
}


// Transpose a NxN Matrix only means the rows becomes columns and cols becomes rows
void transpose(vector<vector<int>>& mat){
    cout << "Transposing " << endl;
    printMatrix(mat);
    cout << endl;

    int R = mat.size();
    int C = mat[0].size();

    for(int r = 0; r< R; r++){
        for(int c = r; c< C; c++){
            std::swap(mat[r][c], mat[c][r]);
        }
    }
    printMatrix(mat);
}

void reverseColums(vector<vector<int>>& mat){
    cout << "Reversing Colums" << endl;
    int R = mat.size();
    int C = mat[0].size();

    for (int i = 0; i< R; i++){
        for(int j = 0, k = C-1; j< k; j++, k--){
            swap(mat[j][i], mat[k][i]);
        }
    }
    printMatrix(mat);
}

void rotateMatrix(vector<vector<int>>& mat){
    cout << "Rotating" << endl;
    transpose(mat);
    reverseColums(mat);
}






