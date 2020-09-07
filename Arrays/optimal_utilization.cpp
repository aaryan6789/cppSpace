#include "_array.h"
/**
 * OPTIMAL UTILIZATION | AMAZON OA
 * Given 2 lists a and b. Each element is a pair of integers where the first integer represents the unique id and the second integer represents a value. Your task is to find an element from a and an element form b such that the sum of their values is less or equal to target and as close to target as possible. Return a list of ids of selected elements. If no pair is possible, return an empty list.
 * 
 * Example 1:
 * Input:
 * a = [[1, 2], [2, 4], [3, 6]]
 * b = [[1, 2]]
 * target = 7
 * 
 * Output: [[2, 1]]
 * Explanation:
 * There are only three combinations [1, 1], [2, 1], and [3, 1], which have a total sum of 4, 6 and 8, respectively.
 * Since 6 is the largest sum that does not exceed 7, [2, 1] is the optimal pair.
 * 
 * Example 2:
 * Input:
 * a = [[1, 3], [2, 5], [3, 7], [4, 10]]
 * b = [[1, 2], [2, 3], [3, 4], [4, 5]]
 * target = 10
 * 
 * Output: [[2, 4], [3, 2]]
 * Explanation:
 * There are two pairs possible. Element with id = 2 from the list `a` has a value 5, and element with id = 4 from the list `b` also has a value 5.
 * Combined, they add up to 10. Similarily, element with id = 3 from `a` has a value 7, and element with id = 2 from `b` has a value 3.
 * These also add up to 10. Therefore, the optimal pairs are [2, 4] and [3, 2].
 * 
 * Example 3:
 * Input:
 * a = [[1, 8], [2, 7], [3, 14]]
 * b = [[1, 5], [2, 10], [3, 14]]
 * target = 20
 * 
 * Output: [[3, 1]]
 * Example 4:
 * 
 * Input:
 * a = [[1, 8], [2, 15], [3, 9]]
 * b = [[1, 8], [2, 11], [3, 12]]
 * target = 20
 * 
 * Output: [[1, 3], [3, 2]]
 */


static bool cmp(vector<int>& a, vector<int>& b){
    return a[1] <= b[1];  //CRITICAL: lists may contain duplicates <= is important
}

// Same as 2 Sum Question but for 2 arrays
vector<vector<int>> optimal(vector<vector<int>> a, vector<vector<int>> b, int target){
    // Sort and Search
    // 1. Sort Based on the values of the intervals
    // 2. Pick 1 from each array
    // 3. Comapare against the target and put them in the result

    vector<vector<int>> res{};

    // Sort both the vector in increasing order of the values
    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end(), cmp);

    auto left = 0;
    auto right = b.size() -1 ;
    int prevDiff = INT8_MAX;

    while( left < a.size() && right > 0){
        int sum = a[left][1] + b[right][1];

        if(sum > target){
            right--;
            continue;
        }
        else{
            int diff = target - sum;

            if(diff < prevDiff){
                prevDiff = diff;
                res.clear();    // Youll reset the result only if you found a better val.
                                // The better val will always be <= target, 
                                // so if the better val is the "target" youll clear
            }
            int begin = right;
            while( begin>= 0 && a[left][1] + b[begin][1] == sum){
                vector<int> temp;
                temp.push_back(a[left][0]);
                temp.push_back(b[begin][0]);

                res.push_back(temp);
                begin--;
            }
        }   //sum <= target
        left++;
    }
    return res;

}