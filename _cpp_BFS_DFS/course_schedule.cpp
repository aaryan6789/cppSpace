#include "_helper.h"

/**
 * Course Schedule I | LeetCode M | 207
 * // PREREQ = Graph --> Adj List --> Detect Cycle in Graph --> Topological Sort
 * // DFS , BFS(Topological Sort)
 * 
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * Some courses may have prerequisites, for example to take course 0 you have to
 * first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs,
 * is it possible for you to finish all courses?
 * 
 * Example 1:
 * Input: 2, [[1,0]] 
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 *              To take course 1 you should have finished course 0. So it is possible.
 * 
 * Example 2:
 * Input: 2, [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 *              To take course 1 you should have finished course 0, and to take course 0 you should
 *              also have finished course 1. So it is impossible.
 * Note:
 * The input prerequisites is a graph represented by a list of edges, 
 * not adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input prerequisites.
 */


// This problem can be seen as a graph probem.
// The prerequisites can be seen as a adjacency list where the 
// 2nd course is a prerequisite of the 1st course.
// i.e we can draw a directed edge from  Course 1 to Course 2 or following.
// e.g : [1, 2] , [2, 3] can be drawn as below
// 1 -> 2
// 2 -> 3

// Now For our problem if we see a cycle in this Graph then we wont be able to
// complete our courses because we would just be stuck in the cycle.
// 
// Read Topological Sorting concept to understand more
// If there is a cycle in the graph, then it is not possible to finish all courses
// (because in that case there is no any topological order of tasks). 
// Both BFS and DFS can be used to solve it.


// Using DFS to Detect Cycle in the Graph
// For DFS, in each visit, we start from a node and keep visiting its neighbors, 
// if at a time we return to a visited node, there is a cycle. 
// Otherwise, start again from another unvisited node and repeat this process. 
// For DFS, it will first visit a node, then one neighbor of it, then one neighbor 
// of this neighbor… and so on. 
// If it meets a node which was visited in the current process of DFS visit, 
// a cycle is detected and we will return false. 
// Otherwise it will start from another unvisited node and repeat this process 
// till all the nodes have been visited. 

// Note that you should make two records: one is to record all the visited nodes 
// and the other is to record the visited nodes in the current DFS visit

void dfs(int node, vector<vector<int>>& graph, vector<int>& visted, bool& cycle);
bool canFinish(int numCourses, vector<vector<int>>& prereq) {
    // First we have to make a Graph form the prerquisites
    vector<vector<int>> graph(numCourses);
    
    for(int i = 0; i< prereq.size(); i++){
        graph[prereq[i][1]].push_back(prereq[i][0]);
    }
    
    bool cycle = false;
    // Keep a Visted vector
    vector<int> visted(numCourses, 0);
    
    for(int i = 0; i< numCourses; i++){
        if(!visted[i]){
            dfs(i, graph, visted, cycle);
        }
    }
    
    return !cycle;
}

void dfs(int node, vector<vector<int>>& graph, vector<int>& visted, bool& cycle){
    // Terminating Condition = Cycle Check Condition
    // If we get to a already visted node then its a cycle.
    if(visted[node] == 1){
        cycle = true;
        return;
    }
    
    visted[node] = 1;       // Mark the node as visted
    // Look for its neighbors and put them on the visited list too
    for(int i = 0; i< graph[node].size(); i++){
        dfs(graph[node][i], graph, visted, cycle);
        
        if(cycle)
            return;
    }
    
    visted[node] = 2;
}