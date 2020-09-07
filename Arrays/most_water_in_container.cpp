// Water Container
#include "_array.h"
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

/**
 * Given n non-negative integers a1, a2, ..., an , where each represents a point
 * at coordinate (i, ai).
 * n vertical lines are drawn such that the two end points of line i is at
 * (i, ai) and (i, 0).
 *
 * Find two lines, which together with x-axis forms a container, such that the
 * container contains the most water.
 *
 * Note: You may not slant the container and n is at least 2.
 *
 * The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7].
 * In this case, the max area of water (blue section) the container can contain
 * is 49.
 *
 * Example:
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 **/
int maxArea(vector<int>& height) {
    std::cout << "\n" << __FUNCTION__ << std::endl;
    for (int i = 0; i< height.size(); i++){
        std::cout <<  height[i] << " ";
    }

    int left = 0;
    int right = height.size() - 1;
    int max_area = 0;

    while (left < right) {
        max_area = max(max_area, (right - left) * min(height[left], height[right]));
        if (height[left] <= height[right]) {
            ++left;
        } else {
            --right;
        }
    }
    std::cout << "\nMax Area = " << max_area;
    return max_area;
}
