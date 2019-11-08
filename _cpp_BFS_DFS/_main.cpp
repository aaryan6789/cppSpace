#include "_helper.h"

using namespace std;
int main(){


    vector<vector<char>> grid = {{'1','1','0','0','0'},
                                 {'1','1','0','0','0'},
                                 {'0','0','1','0','0'},
                                 {'0','0','0','1','1'}};

    // cout << "Num Islands = " << numIslands(grid) << endl;

    // cout << "Num Islands = " << numIslandsBFS(grid) << endl;


    vector<vector<int>> grid2 = {{ 1,  1,  0,  0 , 0 },
                                 { 1 , 1 , 0 , 0 , 0 },
                                 { 0 , 0 , 1 , 0 , 0 },
                                 { 0 , 0 , 0 , 1 , 1 }};

    cout << "Max Area Islands = " << maxAreaOfIsland(grid2) << endl;



}