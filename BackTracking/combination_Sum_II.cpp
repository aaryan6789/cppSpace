#include "_backtracking.h"

/**
 * COMBINATION SUM 2
 * LEETCODE M | 40 | https://leetcode.com/problems/combination-sum-ii/
 * Given a collection of candidate numbers (candidates) and a target number 
 * (target), find all unique combinations in candidates where the candidate 
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note:
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * Example 1:
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 *   [1, 7],
 *   [1, 2, 5],
 *   [2, 6],
 *   [1, 1, 6]
 * ]
 * Example 2:
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 *   [1,2,2],
 *   [5]
 * ]
 */


// BackTracking (Same as Combi Sum 1) 2 changes i+1 and not considering the duplicates

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> record;
    sort(candidates.begin(),candidates.end());
    DFS(candidates, target, record, 0, result);
    return result;
}

void DFS(vector<int>& cand, int curTarget, vector<int>& r, int start, vector<vector<int>>& res){
    
    if(curTarget==0){
        res.push_back(r);
        return;
    }
    
    for(int i = start; i<cand.size(); i++){
        
        // we always want to count the first element in this recursive step even if it is the same 
        // as one before. To avoid overcounting, we just ignore the duplicates
        // after the first element.
        if(i>start && cand[i]==cand[i-1]) 
            continue;
        
        if(curTarget>=cand[i]){
            r.push_back(cand[i]);
            DFS(cand, curTarget-cand[i], r, i+1, res);
            r.pop_back();
        }
    }
}