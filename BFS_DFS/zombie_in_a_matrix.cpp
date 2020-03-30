#include "_helper.h"
/**
 * ZOMBIE IN A MATRIX | AMAZON OA
 * Given a 2D grid, each cell is either a zombie 1 or a human 0. 
 * Zombies can turn adjacent (up/down/left/right) human beings into zombies every hour. 
 * Find out how many hours does it take to infect all humans?

Example:
Input:
[[0, 1, 1, 0, 1],
 [0, 1, 0, 1, 0],
 [0, 0, 0, 0, 1],
 [0, 1, 0, 0, 0]]

Output: 2

Explanation:
At the end of the 1st hour, the status of the grid:
[[1, 1, 1, 1, 1],
 [1, 1, 1, 1, 1],
 [0, 1, 0, 1, 1],
 [1, 1, 1, 0, 1]]

At the end of the 2nd hour, the status of the grid:
[[1, 1, 1, 1, 1],
 [1, 1, 1, 1, 1],
 [1, 1, 1, 1, 1],
 [1, 1, 1, 1, 1]]
 */

int zombieMatrix(vector<vector<int>> grid){
    int R = grid.size();
    int C = grid[0].size();
    int humans = 0;
    queue<pair<int, int>> q;

    for( int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            if(grid[i][j] == 1){
                q.push({i, j});
            }
            if(grid[i][j] == 0){
                humans++;
            }
        }
    }

    if(humans == 0){
        return 0;
    }

    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int count = 0;
    while(!q.empty()){
        int size = q.size();
        
        for(int i = 0; i<size; i++){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            cout << "r c " << r << " " << c << endl; 

            for(auto d : dirs){
                int x = r + d[0];
                int y = c + d[1];

                if(x<0 || y <0 || x>= R || y >= C || grid[x][y] == 1){
                    continue;
                }

                grid[x][y] = 1;
                humans--;
                q.push({x, y});
            }
        }

        count++;
        if(humans == 0)
            return count;

        printMatrix(grid);
    }

    return count;
}

