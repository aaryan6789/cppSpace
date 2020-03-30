
#include "_helper.h"

/**LeetCode M | Num DISTINCT ISLANDS 
 * 
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Count the number of distinct islands. An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.

Example 1:
11000
11000
00011
00011
Given the above grid map, return 1.
Example 2:
11011
10000
00001
11011
Given the above grid map, return 3.

Notice that:
11
1
and
 1
11
are considered different island shapes, because we do not consider reflection / rotation.
Note: The length of each dimension in the given grid does not exceed 50.
*/

// Set of Local Coordinates [RELATIVE]
// Algorithm
// At the beginning, we need to find every island, which we can do using a 
// straightforward depth-first search. 
// The hard part is deciding whether two islands are the same.

// Since two islands are the same if one can be translated to match another, 
// let's translate every island so the top-left corner is (0, 0) 
// For example, if an island is made from squares [(2, 3), (2, 4), (3, 4)], 
// we can think of this shape as [(0, 0), (0, 1), (1, 1)] when anchored at 
// the top-left corner.

// From there, we only need to check how many unique shapes there ignoring 
// permutations (so [(0, 0), (0, 1)] is the same as [(0, 1), (1, 0)]). 

// We use set directly as we have showcased below, 
// but we could have also sorted each list and put those sorted lists in our set
// structure shapes.

// (r - r0, c - c0) to integers.



void DFS(vector<vector<int>>& grid, int r, int c, int i, int j, vector<int>& island){
    int R = grid.size();
    int C = grid[0].size();
    if(r<0 || r>= R || c<0 || c>=C || i<0 || i>= R || j<0 || j>= C || grid[i][j] == 0){
        return;
    }
    
    grid[i][j] = 0;
    island.push_back(r-i);
    island.push_back(c-j);
    
    DFS(grid, r, c, i+1, j, island);
    DFS(grid, r, c, i-1, j, island);
    DFS(grid, r, c, i, j+1, island);
    DFS(grid, r, c, i, j-1, island);
}

int numDistinctIslands(vector<vector<int>>& grid) {
    int R = grid.size();
    int C = grid[0].size();
            
    set<vector<int>> islands = {};      // Unordered Set Would not work as they dont have the capability to have vectors in them

    for(int i = 0; i< R; i++){
        for(int j = 0; j<C; j++){
            if(grid[i][j] == 1){
                vector<int> island;
                DFS(grid, i, j, i, j, island);
                islands.insert(island);
            }
        }
    }
    
    return islands.size();
}


// Using String instea of vetor to keep the shape
// Now we can use the unordered_set
int numDistinctIslandsDFS(vector<vector<int>>& grid) {
    int m = grid.size(), n = m ? grid[0].size() : 0;
    unordered_set<string> islands;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j]) {
                string island;
                distinct(grid, i, j, i, j, island);
                islands.insert(island);
            }
        }
    }
    return islands.size();
}

void distinct(vector<vector<int>>& grid, int i, int j, int r, int c, string& island) {
    int m = grid.size(), n = grid[0].size();
    if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c]) {
        grid[r][c] = 0;
        island += to_string(r - i) + to_string(c - j);
        distinct(grid, i, j, r - 1, c, island);
        distinct(grid, i, j, r + 1, c, island);
        distinct(grid, i, j, r, c - 1, island);
        distinct(grid, i, j, r, c + 1, island);
    }
}


int numDistinctIslandsBFS(vector<vector<int>>& grid) {
    int m = grid.size(), n = m ? grid[0].size() : 0, offsets[] = {0, 1, 0, -1, 0};
    unordered_set<string> islands;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j]) {
                grid[i][j] = 0;
                string island;
                queue<pair<int, int>> todo;
                todo.push({i, j});
                while (!todo.empty()) {
                    pair<int, int> p = todo.front();
                    todo.pop();
                    for (int k = 0; k < 4; k++) {
                        int r = p.first + offsets[k], c = p.second + offsets[k + 1];
                        if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c]) {
                            grid[r][c] = 0;
                            todo.push({r, c});
                            island += to_string(r - i) + to_string(c - j);
                        }
                    }
                }
                islands.insert(island);
            }
        }
    }
    return islands.size();
}