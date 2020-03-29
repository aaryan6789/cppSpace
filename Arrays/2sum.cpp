#include <iostream>
#include <utility>
#include <unordered_map>
#include <vector>
#include <iterator>

#include "_array.h"

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    cout << "Target " << target << endl;
    unordered_map<int, int> hash;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        int numberToFind = target - nums[i];
        auto it = hash.find(numberToFind);
        cout << "Number to find = " << numberToFind << endl;
        if (it != hash.end()) {
            res.push_back(it->second); // to int
            res.push_back(i);
        }
        hash[nums[i]] = i;
    }

    std::cout << "Result Size : " << res.size() << endl;
    cout << "Result Array (Indexes)" << endl;
    for (auto i = res.begin(); i != res.end(); ++i)
        cout << *i << " ";

    return res;
}

// Method 1: 2 Pointer
// 1. Iterate through the array, for each figure out (target -element)
// Time Complexity = O(nlogn) + O(n)

// 1. Sort this array
// 2. 2 variables start, end
// 3. Sum = A[Start] + A[end]
// if sum == target, return the pair, and start++ and end--
// if not , sum<target then start ++ else end --

vector<int> twoSum2(vector<int>& numbers, int target) {
    // Sort the array first
    sort(numbers.begin(), numbers.end());

    int low = 0, high = numbers.size() - 1;
    while (low < high) {
        int sum = numbers[low] + numbers[high];
        if (sum == target)
            return {low + 1, high + 1};
        else if (sum < target)
            ++low;
        else
            --high;
    }
    return {-1, -1};
}
