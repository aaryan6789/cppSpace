#include "_matrix.h"

using namespace std;

void printMatrix(vector<vector<int>>& mat){
    int R = mat.size();
    int C = mat[0].size();

    for(int i = 0; i< R; i++){
        for(int j = 0; j< C; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return;
}



int main(){

    // Initializing 2D vector "vect" with values
    vector<vector<int> > grid {{ 1, 2, 3 },
                               { 4, 5, 6 },
                               { 7, 8, 9 },
                               { 3, 4, 1 } };

    cout  << "ROWS " << grid.size() << endl;
    cout  << "COLS " << grid[0].size() << endl;
    // Displaying the 2D vector
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }


    vector<vector<int> > grid2 {{ 1, 2, 3, 4 },
                               { 5, 6, 7, 8 },
                               { 9, 10, 11, 12},
                               { 13, 14, 15, 16 } };

    cout << endl;
    // transpose(grid2);

    printMatrix(grid2);
    rotateMatrix(grid2);

    vector<vector<int> > grid3 = {{ 1, 1, 1, 1 },
                                { 1, 0, 1, 1 },
                                { 1, 1, 0, 1 },
                                { 1, 1, 1, 1 } };

    setZeroes(grid3);
    printMatrix(grid3);


    vector<vector<int>> grid4 {{5, 1}, {4, 5}};
    vector<vector<int> > grid5 {{5, 1, 7}, {4, 8, 5}};
    vector<vector<int> > grid6 {{1, 9, 9}, {9, 9, 9}, {9, 9, 9}};
    vector<vector<int> > grid7 {{10, 7, 3}, {12, 11, 9}, {1, 2, 8}};
    vector<vector<int> > grid8 {{20, 20, 3}, {20, 3, 20}, {3, 20, 20}};

    cout << "Max score should be 4: " << maxScore(grid4) << "\n";
    cout << "Max score should be 4: " << maxScore(grid5) << "\n";
    cout << "Max score should be 1: " << maxScore(grid6) << "\n";
    cout << "Max score should be 8: " << maxScore(grid7) << "\n";
    cout << "Max score should be 3: " << maxScore(grid8) << "\n";

    vector<int> A = {1, 0, 0, 0, 0, 1, 0, 0};
    vector<int> res = prisonAfterNDays2(A, 1);

    for(auto i : res){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}


unordered_map<int, vector<int>> sumMap;
int maxSum = INT_MIN;

void pushInMap(vector<vector<int>>& m, int R, int C, int k, int currSum){
    for(int i = R; i< R+k; i++){
        for(int j = C; j< C+k; j++){
            sumMap[currSum].push_back(m[i][j]);
        }
    }
}



int calcSum(vector<vector<int>>& m, int R, int C, int k) {
    int sum = 0;
    // cout << " R " << R << " C " << C << " k " << k << " sum " << sum << endl;
     
    for(int i = R; i< R+k; i++){
        for(int j = C; j< C+k; j++){
            // cout << "m[" << i << "][" << j << "] " << m[i][j] << " sum ";
            sum += m[i][j];
            // cout << sum << endl;
        }
    }
    

    return sum;
}

// Given a rectangular matrix m and an integer k, consider all the k × k contiguous square submatrices of m. Your task is the following:

// Calculate the sum of all numbers within each k × k submatrix.
// Determine the maximum of all these sums.
// Find all the distinct numbers that appear in at least one of the k × k submatrices with a sum equal to the maximum. Each integer from these squares should be calculated exactly once. Return the sum of these distinct numbers.
// Note: k × k contiguous square submatrix contains k2 cells and is built from intersection of k contiguous rows and k contiguous columns. See example for better understanding.

// Example

// For

// m = [[1, 0, 1, 5, 6],
//      [3, 3, 0, 3, 3],
//      [2, 9, 2, 1, 2],
//      [0, 2, 4, 2, 0]]
// and k = 2, the output should be bestSquares(m, k) = 29.



// If we consider all the 2 × 2 squares in m, there are 3 of them with a maximum sum of 17:

// [[5, 6],
//  [3, 3]]
// (5 + 6 + 3 + 3 = 17)

// [[3, 3],
//  [2, 9]]
// (3 + 3 + 2 + 9 = 17)

// [[9, 2],
//  [2, 4]]
// (9 + 2 + 2 + 4 = 17)

// Among these 3 squares which each have the maximum sum, only the distinct numbers 2, 3, 4, 5, 6, and 9 appear. So the answer is 2 + 3 + 4 + 5 + 6 + 9 = 29.

// Input/Output

// [execution time limit] 0.5 seconds (cpp)

// [input] array.array.integer m

// A rectangular matrix of integers.

// Guaranteed constraints:
// 1 ≤ m.length ≤ 100,
// 1 ≤ m[i].length ≤ 100,
// 0 ≤ m[i][j] ≤ 100.

// [input] integer k

// Guaranteed constraints:
// 1 ≤ k ≤ min(m.length, m[i].length).

// [output] integer

// The sum of all distinct integers within the k × k squares with the maximal sum.

int bestSquares(vector<vector<int>> m, int k) {
    int R = m.size();
    int C = m[0].size();
    
    int currSum = 0;
    int  maxSum2 = 0;
    
    for(int i = 0; i<=R-k ; i++){
        for(int j = 0; j<=C-k; j++){
            currSum = calcSum(m, i, j, k);
            
            pushInMap(m, i, j, k, currSum);
            
            maxSum = max(currSum, maxSum);
        }
    }
    
    sort(sumMap[maxSum].begin(), sumMap[maxSum].end());
    for(int i = 0; i<sumMap[maxSum].size(); i++){
        cout << sumMap[maxSum][i] << " ";
        if(sumMap[maxSum][i] != sumMap[maxSum][i+1])
            maxSum2 += sumMap[maxSum][i];
    }
    
    cout << "Sum " << maxSum2 << endl;
    return maxSum2;
}
