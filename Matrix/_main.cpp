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