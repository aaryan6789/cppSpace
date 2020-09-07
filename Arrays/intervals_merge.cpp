
#include "_array.h"
/**
 * PATTERN INTERVALS
 * LeetCode M 56 | https://leetcode.com/problems/merge-intervals/
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * Example 1:
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
 *
 * Example 2:
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 *
 * NOTE: input types have been changed on April 15, 2019. Please reset to default
 * code definition to get new method signature.
 */

/** ALGORITHM
 * 1. Sort the intervals based on increasing order of starting time.
2. Push the first interval on to a stack.
3. For each interval do the following
   a. If the current interval does not overlap with the stack
       top, push it.
   b. If the current interval overlaps with stack top and ending
       time of current interval is more than that of stack top,
       update stack top with the ending  time of current interval.
4. At the end stack contains the merged intervals. */
static bool compare(vector<int>& a, vector<int>& b){
    return a[0] < b[0];
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    if(intervals.size()== 0){
        return res;
    }

    // Sort the Intervals
    sort(intervals.begin(), intervals.end(), compare);

    // Push the first interval in the res
    res.push_back(intervals[0]);

    // Now compare the 1st interval onwards
    for(int i = 1; i< intervals.size(); i++){
        vector<int>& last = res.back();

        //Check for overlapping boundaries in the intervals and merge them suitably
        if(last[1] < intervals[i][0]){                      // {1, 8} [9, 10]
            res.push_back(intervals[i]);
        }
        else{
            last[1] = max(last[1] , intervals[i][1]);       // {0, 3}, {2, 6}
        }
    }

    return res;

}