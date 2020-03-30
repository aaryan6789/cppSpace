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


int bfs(vector<vector<char>>& grid, int i, int j);
int treasure_island_II(vector<vector<char>>& grid){
    int R = grid.size();
    int C = grid[0].size();
    int minSteps = INT_MAX;
    cout << "Here " << endl;
    int currMin;
    for(int i = 0; i< R; i++){
        for(int j = 0; j< C; j++){
            if(grid[i][j] = 'S'){
                cout << "Here 2" << endl;
                currMin = bfs(grid, i, j);
                minSteps = min(minSteps, currMin);
            }
        }
    }

    cout << "minSteps " << minSteps << endl;
    return minSteps;
}

int bfs(vector<vector<char>>& grid, int i, int j){
    int R = grid.size();
    int C = grid[0].size();
    cout << "Here 3" << i << j << endl;
    
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    
    bool visited[R][C] = {false};

    vector<vector<int>> dirs {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dist = 0;
    cout << "Here 4" << q.size() <<  endl;
    
    while(!q.empty()){
        int size = q.size();
        cout << "Here 4" << size << endl;
    
        while( size != 0){
            pair<int, int> temp = q.front();
            q.pop();

            int r = temp.first;
            int c = temp.second;
            visited[r][c] = true;
            cout << "r c " << r << " " << c << endl;

            for(auto dir : dirs){
                int i = r + dir[0];
                int j = c + dir[1];
                cout << "i j " << i << " " << j << grid[i][j] << endl;
                    
                if(i<0 || i>= R || j<0 || j>= C || grid[i][j] == 'D' || visited[i][j] == true){
                    
                    // cout << "i j " << i << " " << j << grid[i][j] << endl;
                    continue;
                }

                if(grid[i][j] == 'X'){
                    cout << "dist " << dist << endl;
                    return dist;
                }
                
                q.push({i, j});
            }
            dist++;
        }
        size--;
    }

    return dist;
}

