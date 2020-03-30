/** Voyage | Applied Intuition
 * 
 * Check if a destination is reachable from source with two movements allowed
 * Given coordinates of a source point (x1, y1) determine if it is possible to
 * reach the destination point (x2, y2).
 * From any point (x, y) there only two types of valid movements:
 * (x, x + y) and (x + y, y).
 *
 * Return a boolean true if it is possible else return false.
 *
 * Note: All coordinates are positive.
   Asked in: Expedia, Telstra

Examples:
Input : (x1, y1) = (2, 10)
        (x2, y2) = (26, 12)
Output : True
(2, 10)->(2, 12)->(14, 12)->(26, 12)
is a valid path.

Input : (x1, y1) = (20, 10)
        (x2, y2) = (6, 12)
Output : False
No such path is possible because x1 > x2 and coordinates are positive
 */

// DFS based Solution
int isReachable(int sx, int sy, int dx, int dy) {
    // base case
    if (sx > dx || sy > dy)
        return 0;

    // For 1st column or row
    if ((dx == 0) || (dy == 0))
        return 1;

    // current point is equal to destination
    if (sx == dx && sy == dy)
        return 1;

    // check for other 2 possibilities
    return (isReachable(sx + 1, sy, dx, dy) ||
            isReachable(sx, sy + 1, dx, dy));
}

int uniquePathsR(int m, int n) {
    // If either given row number is first or given column
    // number is first
    if (m == 1 || n == 1)
        return 1;

    return uniquePathsR(m - 1, n) + uniquePathsR(m, n - 1);
}

// DP based Solution
int uniquePaths(int m, int n) {
    // Create a 2D table to store results of subproblems
    int count[m][n];

    // Count of paths to reach any cell in first column is 1
    for (int i = 0; i < m; i++)
        count[i][0] = 1;

    // Count of paths to reach any cell in first row is 1
    for (int j = 0; j < n; j++)
        count[0][j] = 1;

    // Calculate count of paths for other cells in
    // bottom-up manner using the recursive solution
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++)

            // By uncommenting the last part the code calculatest he total
            // possible paths if the diagonal Movements are allowed
            count[i][j] = count[i - 1][j] + count[i][j - 1]; //+ count[i-1][j-1];
    }
    return count[m - 1][n - 1];
}

