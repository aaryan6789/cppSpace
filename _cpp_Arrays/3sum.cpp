#include "_array.h"
using namespace std;
/**
 * LEETCODE M | 15
 * Given an array nums of n integers, are there elements a, b, c in nums
 * such that a + b + c = 0?
 * Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 * The solution set must not contain duplicate triplets.
 *
 * Example:
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 *
 * A solution set is:
 * [
 *   [-1, 0, 1],
 *   [-1, -1, 2]
 * ]
 */

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;

    if(n<3)
        return res;


    for (int i=0; i<nums.size(); i++) {
        if ((i>0) && (nums[i]==nums[i-1]))
            continue;

        int l = i+1;
        int r = nums.size()-1;
        while (l<r) {
            int sum = nums[i]+ nums[l]+ nums[r];
            if (sum>0){
                r--;
            }
            else if (sum<0) {
                l++;
            }
            else {
                res.push_back(vector<int> {nums[i], nums[l], nums[r]});

                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (l < r && nums[l]==nums[l+1])
                    l++;

                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (l < r && nums[r]==nums[r-1])
                    r--;

                l++;
                r--;
            }
        }
    }
    return res;
}



vector<vector<int>> threeSum2(vector<int>& num) {
    vector<vector<int> > res;           // Result Vector

    std::sort(num.begin(), num.end());  // Sort the Vector

    for (int i = 0; i < num.size(); i++) {

        int target = -num[i];
        int front = i + 1;
        int back = num.size() - 1;

        while (front < back) {

            int sum = num[front] + num[back];

            // Finding answer which start from number num[i]
            if (sum < target)
                front++;

            else if (sum > target)
                back--;

            else {
                vector<int> triplet(3, 0);
                triplet[0] = num[i];
                triplet[1] = num[front];
                triplet[2] = num[back];
                res.push_back(triplet);

                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (front < back && num[front] == triplet[1])
                    front++;

                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (front < back && num[back] == triplet[2])
                    back--;
            }

        }

        // Processing duplicates of Number 1
        while (i + 1 < num.size() && num[i + 1] == num[i])
            i++;

    }

    return res;
}