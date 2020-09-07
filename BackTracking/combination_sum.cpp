#include "_backtracking.h"
/** COMBINATION SUM | LEETCODE M | 39 
 * https://leetcode.com/problems/combination-sum/
 * Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
 */

// Using Recursion + DFS (BackTracking)

void DFS(vector<int>& cand, int curTarget, vector<int>& r, int start, vector<vector<int>>& res);
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> record;

    // Sort it first so that the candidates would not have any duplicate values
    sort(candidates.begin(), candidates.end());
    DFS(candidates, target, record, 0, result);
    return result;
}

void DFS(vector<int>& cand, int curTarget, vector<int>& r, int start, vector<vector<int>>& res){
    // if the sum of the elements is equal to the target, push this combination into the result
    if(curTarget==0){
        res.push_back(r);
        return;
    }
    
    for(int i = start; i<cand.size(); i++){
        if(curTarget>=cand[i]){                         // if current element is bigger than the assigned target, there is 
                                                        //  no need to keep searching, since all the numbers are positive and sorted
            r.push_back(cand[i]);                       //push the valid candidate into the elements vector.
            DFS(cand, curTarget-cand[i], r, i, res);    // keep searching for new elements with start as i since here duplicates are allowed
//                 for(auto i : r)
//                     cout << i << " " ;
            
//                 cout << "Popping " << r.back();
//                 cout << endl;
            r.pop_back();
        }
    }
}