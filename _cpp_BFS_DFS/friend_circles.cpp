#include "_helper.h"

/** 547 | Friend Circles | LeetCode M | https://leetcode.com/problems/friend-circles/
 * There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

Example 1:
Input: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
The 2nd student himself is in a friend circle. So return 2.
Example 2:
Input: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
Note:
N is in range [1,200].
M[i][i] = 1 for all students.
If M[i][j] = 1, then M[j][i] = 1.
 */
void dfs(vector<vector<int>>& M, vector<int>& visited, int i);
int findCircleNum(vector<vector<int>>& M) {
    vector<int> visited(M.size(), 0);
    int i = 0;
    int len = 0;
    for (i = 0; i < M.size(); i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            len++;
            dfs(M, visited, i);
        }
    }
    return len;
}

void dfs(vector<vector<int>>& M, vector<int>& visited, int i) {
    int j = 0;
    for (j = 0; j < M[0].size(); j++) {
        if (M[i][j] == 1 && visited[j] == 0) {
            visited[j] = 1;
            dfs(M, visited, j);
        }
    }
}
/** DFS Complexity Analysis
// Time complexity : O(n^2) The complete matrix of size n^2 is traversed.
// Space complexity : O(n). visited array of size n is used.
**/

int findCircleNum2(vector<vector<int>>& M) {
    vector<int> visited(M.size());
    int count = 0;
    queue<int> q;
    
    for(int i = 0; i<M.size();i++){
        if(!visited[i]){
            q.push(i);
            while(!q.empty()){
                int i = q.front();
                q.pop();
                visited[i]  = 1;
                for( int j = 0; j<M.size(); j++){
                    if(M[i][j] == 1 && visited[j] == 0){
                        q.push(j);
                    }
                }
            }
            count++;
        }
    }
    
    return count;
}
/**
 * BFS Complexity Analysis
Time complexity : O(n^2) as The complete matrix of size n^2 is traversed.
Space complexity : O(n). A queue and visited array of size n is used.
 */