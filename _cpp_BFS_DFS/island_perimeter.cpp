#include "_helper.h"
using namespace std;
/**
 * LeetCode Easy | https://leetcode.com/problems/island-perimeter/
 *
 * You are given a map in form of a two-dimensional integer grid where 1
 * represents land and 0 represents water.
 * Grid cells are connected horizontally/vertically (not diagonally).
 * The grid is completely surrounded by water, and there is exactly one island
 * (i.e., one or more connected land cells).
 *
 * The island doesn't have "lakes" (water inside that isn't connected to the
 * water around the island).
 * One cell is a square with side length 1.
 * The grid is rectangular, width and height don't exceed 100.
 * Determine the perimeter of the island.
 *
 * Example:
 *
 * Input:
 * [[0,1,0,0],
 *  [1,1,1,0],
 *  [0,1,0,0],
 *  [1,1,0,0]]
 *
 * Output: 16
 *
 * Explanation: The perimeter is the 16 yellow stripes in the image below:
 */
/**
 * For every one we know that the square consists of four walls.
Now for every one found in the grid, don't add the walls which are surrounded by other blocks (i.e. 1s).
Add the ones not surrounded by any 1s (i.e. have 0 as adjacent element).
 */
int numNeighbors(vector<vector<int>>& grid, int r, int c){
    int R = grid.size();
    int C = grid[0].size();
    int count = 0;

    if (r<0 || c < 0 || r>=R || c>= C || grid[r][c] == 0){
        return 0;
    }

    if(r-1>=0 && grid[r-1][c] == 1){
        count++;
    }

    if(r+1<R && grid[r+1][c] == 1){
        count++;
    }

    if(c-1>=0 && grid[r][c-1] == 1){
        count++;
    }

    if(c+1<C && grid[r][c+1] == 1){
        count++;
    }

    return count;

}

int islandPerimeter(vector<vector<int>>& grid) {
    if (grid.empty()){
        return 0;
    }

    int R = grid.size();
    int C = grid[0].size();
    int perimeter = 0;

    for(int i = 0; i< R; i++){
        for(int j = 0; j< C; j++){
            if(grid[i][j] == 1){
                perimeter = perimeter + (4 - numNeighbors(grid, i, j));
            }
        }
    }

    return perimeter;

}
