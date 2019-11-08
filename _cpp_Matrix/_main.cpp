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
    return 0;
}