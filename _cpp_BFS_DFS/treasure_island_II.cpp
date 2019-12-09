#include "_helper.h"
/** TREASURE ISLAND II | AMAZON OA |
 * MULTI SOURCE BFS
 * You have a map that marks the locations of treasure islands. Some of the map area has jagged rocks and dangerous reefs. Other areas are safe to sail in. There are other explorers trying to find the treasure. So you must figure out a shortest route to one of the treasure islands.

Assume the map area is a two dimensional grid, represented by a matrix of characters. You must start from one of the starting point (marked as S) of the map and can move one block up, down, left or right at a time. The treasure island is marked as X. Any block with dangerous rocks or reefs will be marked as D. You must not enter dangerous blocks. You cannot leave the map area. Other areas O are safe to sail in. Output the minimum number of steps to get to any of the treasure islands.

Example:

Input:
[['S', 'O', 'O', 'S', 'S'],
 ['D', 'O', 'D', 'O', 'D'],
 ['O', 'O', 'O', 'O', 'X'],
 ['X', 'D', 'D', 'O', 'O'],
 ['X', 'D', 'D', 'D', 'O']]

Output: 3
Explanation:
You can start from (0,0), (0, 3) or (0, 4). The treasure locations are (2, 4) (3, 0) and (4, 0). Here the shortest route is (0, 3), (1, 3), (2, 3), (2, 4).
 */

// BFS using an additional integer matrix to store path length in place 

vector<vector<int>> dirs {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int treasure_island_II(vector<vector<char>>& grid){
    int R = grid.size();
    int C = grid[0].size();

    vector<vector<int>> visited;
    for(int i = 0; i< R; i++){
        for(int j = 0; j< C; j++){
            visited[i][j] = 0;
        }
    }

    queue<pair<int, int>> q;

    for(int i = 0; i< R; i++){
        for(int j = 0; j< C; j++){
            if(grid[i][j] = 'S'){
                q.push({i, j});
                grid[i][j] = 'D';   // Mark them visited
            }
        }
    }

    int dist = 0;
    while(!q.empty()){
        pair<int, int> temp = q.front();
        q.pop();

        int r = temp.first;
        int c = temp.second;
        int currDist = grid[r][c]; 

        for( auto dir : dirs){
            int i = r + dir[0];
            int j = c + dir[1];

            if(i>0 || i<= R || j<0 || j>= C || grid[i][j] != 'O'){
                continue;
            }

            if(grid[i][j] == 'X'){
                return dist;
            }

            grid[i][j] = 'D'; 
        }

        dist++;
    }
}