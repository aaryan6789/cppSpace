"""
LeetCode Easy | https://leetcode.com/problems/island-perimeter/

You are given a map in form of a two-dimensional integer grid where 1
represents land and 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally).
The grid is completely surrounded by water, and there is exactly one island
(i.e., one or more connected land cells).

The island doesn't have "lakes" (water inside that isn't connected to the
water around the island).

One cell is a square with side length 1.
The grid is rectangular, width and height don't exceed 100.

Determine the perimeter of the island.

Example:
Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]
Output: 16

Explanation: The perimeter is the 16 yellow stripes in the image below:
"""

# For every one we know that the square consists of four walls.
# Now for every one found in the grid, don't add the walls which are surrounded by other blocks (i.e. 1s).
# Add the ones not surrounded by any 1s (i.e. have 0 as adjacent element).


def islandPerimeter(grid):
    if not grid:
        return 0
    rows = len(grid)
    cols = len(grid[0])
    peri = 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                if i == 0 or grid[i-1][j] == 0:
                    peri += 1

                if j == 0 or grid[i][j-1] == 0:
                    peri += 1

                if i == rows-1 or grid[i+1][j] == 0:
                    peri += 1

                if j == cols-1 or grid[i][j+1] == 0:
                    peri += 1

    return peri

