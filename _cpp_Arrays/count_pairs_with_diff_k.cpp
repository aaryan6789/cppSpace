#include "_array.h"

/**
 * Given an array, count all the distinct pairs with difference K.
 */
// Using Hash Map
// 1. Parse through the array and push the number in a hash Map
// 2. Check if for the number any nums[i] + k or nums[i] - k exist or not
int findPairs2(vector<int>& nums, int k) {
    if(nums.empty() || k < 0)
        return 0;
    unordered_map<int, int> mp;

    for(auto num : nums){
        mp[num]++;
    }

    int res = 0;

    for(auto num : nums){
        if(mp.find(num) == mp.end())
            continue;
        if(k == 0){
            res += mp[num] >= 2 ? 1 : 0;
        }
        else {
            if(mp.find(num - k) != mp.end())
                 res++;
            if(mp.find(num + k) != mp.end())
                res++;
        }
        mp.erase(num);
    }

    std::cout << "\nPairs with difference " << k << " are " << res << std::endl;
    return res;
}



// Using  Sorting and 2 Pointers
// Time Complexity = O(nLogn) + O(n)
int findPairs(vector<int>& nums, int k) {
        if(nums.size() == 0){
            return 0;
        }

        // Sort the Vector Array
        std::sort(nums.begin(), nums.end());

        int left = 0;
        int right = 0;
        int count = 0;
        int diff;

        // std::cout << "Sorted \n";
        // for (auto x : nums)
        //     cout << x << " ";

        while(left < nums.size() || right < nums.size()) {
            if(left == right){
                right++;
            }
            diff = nums[right] - nums[left];
            if (diff == k) {
                count++;
                left++;
                // skip duplicates
                while (left < nums.size() && (nums[left] == nums[left - 1]))
                    left++;
                while (right < nums.size() && (nums[right] == nums[right - 1]))
                    right++;
            }
            else if (diff < k){
                right++;
            }
            else{
                left++;
            }
        }
        //std::cout << "\nPairs with difference " << k << " are " << count << std::endl;
        return count;
    }
