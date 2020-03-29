#include "_array.h"
#include <algorithm>
#include <cmath>
/**
 * LeetCode M | 987
 *
 * We have a list of points on the plane.
 * Find the K closest points to the origin (0, 0).
 *
 * (Here, the distance between two points on a plane is the Euclidean distance.)
 *
 * You may return the answer in any order.
 * The answer is guaranteed to be unique (except for the order that it is in.)
 *
 * Example 1:
 * Input: points = [[1,3],[-2,2]], K = 1
 * Output: [[-2,2]]
 * Explanation:
 * The distance between (1, 3) and the origin is sqrt(10).
 * The distance between (-2, 2) and the origin is sqrt(8).
 * Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
 * We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
 *
 * Example 2:
 * Input: points = [[3,3],[5,-1],[-2,4]], K = 2
 * Output: [[3,3],[-2,4]]
 * (The answer [[-2,4],[3,3]] would also be accepted.)
 *
 * Note:
 * 1> 1 <= K <= points.length <= 10000
 * 2> -10000 < points[i][0] < 10000
 * 3> -10000 < points[i][1] < 10000
 */

// Functor for comparison
static bool comp(vector<int>& a, vector<int>& b){
    return sqrt(a[0]*a[0] + a[1]*a[1]) < sqrt(b[0]*b[0]+b[1]*b[1]);
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int K){
    std::nth_element(points.begin(), points.begin()+K, points.end(), comp);
    points.resize(K);
    return points;
}

#include <queue>
typedef pair<double, int> point;
vector<vector<int>> kClosestByHeap(vector<vector<int>>& points, int K) {

    // Make a Heap (Max Heap) using priority_queue
    vector<vector<int>> res {};
    priority_queue<point, vector<point>, greater<point>> pq;

    for(int i = 0; i< points.size(); i++){
        int x = points[i][0];
        int y = points[i][1];

        double dist = sqrt(x*x + y*y);

        pq.push(make_pair(dist, i));
    }

    // Get the top K elements from the heap
    while(K--){
        int index = pq.top().second;
        res.push_back(points[index]);
        pq.pop();
    }

    return res;
}