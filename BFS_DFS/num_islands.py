"""
https://leetcode.com/problems/number-of-islands/
LeetCode M | Number of Islands

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands
horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input:
11110
11010
11000
00000
Output: 1

Example 2:
Input:
11000
11000
00100
00011

Output: 3
"""

# Using DFS:
# 1. Parse through the Matrix and Whenever you see a 1 you trigger the DFS.
# 2. In the DFS function we check the top, left, right, bottom neighbors and
#     mark them visited if its reached from the root node.

def dfs(grid, r, c):
    R = len(grid)
    C = len(grid[0]) 

    if r<0 or c<0 or r>=R or c>= C or grid[r][c] == 0:
        return

    grid[r][c] = 0

    dfs(grid, r+1, c)
    dfs(grid, r-1, c)
    dfs(grid, r, c+1)
    dfs(grid, r, c+1)


def numIslands(grid):
    if grid is None:
        return 0
    
    R = len(grid)
    C = len(grid[0])

    count = 0

    for i in range(R):
        for j in range(C):
            if grid[i][j] == 1:
                count += 1
                dfs(grid, i, j)
    
    return count



