"""

 * Leetcode M | https://leetcode.com/problems/max-area-of-island/
 * Max Area of Island
 *
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's
 * (representing land) connected 4-directionally (horizontal or vertical.)
 * You may assume all four edges of the grid are surrounded by water.
 *
 * Find the maximum area of an island in the given 2D array.
 * (If there is no island, the maximum area is 0.)
 *
 * Example 1:
 *
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],
 *  [0,0,0,0,0,0,0,1,1,1,0,0,0],
 *  [0,1,1,0,1,0,0,0,0,0,0,0,0],
 *  [0,1,0,0,1,1,0,0,1,0,1,0,0],
 *  [0,1,0,0,1,1,0,0,1,1,1,0,0],
 *  [0,0,0,0,0,0,0,0,0,0,1,0,0],
 *  [0,0,0,0,0,0,0,1,1,1,0,0,0],
 *  [0,0,0,0,0,0,0,1,1,0,0,0,0]]
 *
 * Given the above grid, return 6.
 * Note the answer is not 11, because the island must be connected 4-directionally.
 *
 * Example 2:
 * [[0,0,0,0,0,0,0,0]]
 * Given the above grid, return 0.
 *
 * Note: The length of each dimension in the given grid does not exceed 50.
"""

def dfs(grid, r, c):
    R = len(grid)
    C = len(grid[0])

    if r<0 or c<0 or c>=C or r>=R or grid[r][c] == 0:
        return 0

    grid[r][c] = 0

    return (1 + dfs(grid, r+1, c) +
                dfs(grid, r-1, c) + 
                dfs(grid, r, c-1) + 
                dfs(grid, r, c+1) )

def maxAreaOfIsland(grid):
    """
    :type grid: List[List[int]]
    :rtype: int
    """
    
    R = len(grid)
    C = len(grid[0])
    
    currArea = 0
    maxArea = 0
    
    for i in range(R):
        for j in range(C):
            if grid[i][j] == 1:
                currArea = dfs(grid, i, j)
                maxArea = max(currArea, maxArea)
                
    return maxArea


int maxAreaOfIslandBFS(vector<vector<int>>& grid) {
    if (grid.empty()){
        return 0;
    }
    
    int R = grid.size();
    int C = grid[0].size();
    int max_area = 0;
    int cur_area;
    
    queue<pair<int, int>> q;
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    
    for(int i = 0; i< R; i++){
        for(int j = 0; j< C; j++){
            if(grid[i][j] == 1){
                q.push({i, j});
                grid[i][j] = 0;         // Mark Visited
                cur_area = 0;
                
                while(!q.empty()){
                    pair<int, int> t = q.front() ; q.pop();
                    int x = t.first;
                    int y = t.second;
                    
                    cur_area += 1;

                    
                    for(auto& d : dirs){
                        int r = x + d[0];
                        int c = y + d[1];
                        
                        if(r<0 || r>=R || c<0 || c>= C || grid[r][c] == 0)
                            continue;
                        
                        grid[r][c] = 0;
                        q.push({r, c});
                    }
                }
                max_area = max(max_area, cur_area);
            }
        }
    }
    
    return max_area;
}