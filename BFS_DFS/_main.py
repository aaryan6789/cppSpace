from num_islands import *
from perimeter_island import *


def main():
    print("BFS DFS 2020")

    grid = [[1, 1, 1],
            [0, 0, 0],
            [0, 1, 0]]

    print(numIslands(grid))
    print(islandPerimeter(grid))


if __name__ == "__main__":
    main()