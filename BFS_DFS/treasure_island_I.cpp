

/** TREASURE ISLAND I
 * You have a map that marks the location of a treasure island. 
 * Some of the map area has jagged rocks and dangerous reefs. Other areas are
 * safe to sail in. There are other explorers trying to find the treasure. 
 * So you must figure out a shortest route to the treasure island.

Assume the map area is a two dimensional grid, represented by a matrix of characters. You must start from the top-left corner of the map and can move one block up, down, left or right at a time. The treasure island is marked as X in a block of the matrix. X will not be at the top-left corner. Any block with dangerous rocks or reefs will be marked as D. You must not enter dangerous blocks. You cannot leave the map area. Other areas O are safe to sail in. The top-left corner is always safe. Output the minimum number of steps to get to the treasure.

Example:

Input:
[['O', 'O', 'O', 'O'],
 ['D', 'O', 'D', 'O'],
 ['O', 'O', 'O', 'O'],
 ['X', 'D', 'D', 'O']]

Output: 5
Explanation: Route is (0, 0), (0, 1), (1, 1), (2, 1), (2, 0), (3, 0) The minimum route takes 5 steps.
 */
#include "_helper.h"

// Using DFS 
// Similar to word Search as I have to recreate the Matrix.

void DFS(vector<vector<char>>& grid, int r, int c, int curr, int& res);
int treasure_island(vector<vector<char>>& grid){
    int R = grid.size();
    int C = grid[0].size();

    int res = INT_MAX;

    DFS(grid, 0, 0, 0, res);

    return res;
}

void DFS(vector<vector<char>>& grid, int r, int c, int curr, int& res){
    int R = grid.size();
    int C = grid[0].size();

    // Terminating condition
    if(r<0 || r>= R || c < 0 || c >= C || grid[r][c] == 'D'){
        return;
    }

    // Cache the character first
    char ch = grid[r][c];

    // If we reached the destination then calculate the res as the min
    if(grid[r][c] == 'X'){
        res = min(res, curr);
        return;
    }

    // Mark this place visited
    grid[r][c] = 'D';

    DFS(grid, r+1, c, curr + 1, res);
    DFS(grid, r, c+1, curr + 1, res);
    DFS(grid, r-1, c, curr + 1, res);
    DFS(grid, r, c-1, curr + 1, res);

    grid[r][c] = ch;

    return;
}

// Time Complexity = O(R*C)
// Space Complexity = O(R*C)

// Similar Questions:
// 1. Walls And Gates https://leetcode.com/problems/walls-and-gates/
// 2. https://leetcode.com/problems/minimum-knight-moves/
// 3. 

// Using BFS

// BFS uses a Queue.
// Its Important to use the queue as in this case there is only one Source
// But in other problems there can be multiple sources.
// For multiple source problems use the BFS Technique always.


int treasure_island_BFS(vector<vector<char>>& grid){
    int R = grid.size();
    int C = grid[0].size();

    queue<pair<int, int>> q;
    q.push({0, 0});

    int res = 0;
    grid[0][0] = 'D';

    while( !q.empty()){
        for(int i = 0; i<q.size(); i++){
            pair<int, int> temp = q.front();
            int r = temp.first;
            int c = temp.second;
            cout << "r c " << r << " " << c << " res " << res << endl; 
            q.pop();

            if (grid[r][c] == 'X'){
                return res;
            }

            // Mark Them visited
            grid[r][c] = 'D';

            if(r+1<R && grid[r+1][c] != 'D'){
                q.push({r+1, c});
                // grid[r+1][c] = 'D';
            }

            if(r-1 >= 0 && grid[r-1][c] != 'D'){
                q.push({r-1, c});
                // grid[r-1][c] = 'D';
            }

            if(c+1 <C && grid[r][c+1] != 'D'){
                q.push({r, c+1});
                // grid[r][c+1] = 'D';
            }

            if(c-1 >=0 && grid[r][c-1] != 'D'){
                q.push({r, c-1});
                // grid[r][c-1] = 'D';
            }
        }
        res++;
    }

    return -1;

}




















// // BFS
// int min_moves(vector<vector> &v){
// int n=v.size(),i,j,m=v[0].size(),res=INT_MAX;
// char c;
// vector x;
// queue<vector> q;
// q.push({0,0,0});
// while(!q.empty()){
// x=q.front();
// c=v[x[0]][x[1]];
// if(c=='X') return x[2];
// v[x[0]][x[1]]='.';
// for(i=-1;i<=1;i++){
// for(j=-1;j<=1;j++){
// if(abs(i)==abs(j) || (x[0]+i)<0 || (x[1]+j)<0 || (x[0]+i)>=n || (x[1]+j)>=m || v[x[0]+i][x[1]+j]=='D' || v[x[0]+i][x[1]+j]=='.') continue;
// q.push({x[0]+i,x[1]+j,x[2]+1});
// }
// }
// q.pop();
// }
// return 0;
// }