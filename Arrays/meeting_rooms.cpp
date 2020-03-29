#include "_array.h"

/**
 * PATTERN INTERVALS
 * Leetcode E
 * Given an array of meeting time intervals consisting of start and end times
 * [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.
 *
 * Example 1:
 * Input: [[0,30],[5,10],[15,20]]
 * Output: false
 *
 * Example 2:
 * Input: [[7,10],[2,4]]
 * Output: true
 */

// Sorting and searching
// The idea here is to sort the meetings by starting time.
// Then, go through the meetings one by one and make sure that each meeting ends
//  before the next one starts.

// Time complexity : O(nlogn). The time complexity is dominated by sorting.
// Once the array has been sorted, only O(n) time is taken to go through the array
// and determine if there is any overlap.
// Space complexity : O(1). Since no additional space is allocated.

bool canAttendMeetings(vector<vector<int>>& intervals) {
    if(intervals.empty()){
        return true;
    }

    // sort(intervals.begin(), intervals.end());
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {return a[0] < b[0];});

    for(int i = 0; i< intervals.size()-1; i++){
        if(intervals[i][1] > intervals[i+1][0]){
            return false;
        }
    }

    return true;
}


/**
 * Given an array of meeting time intervals consisting of start and end times
 * [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
 *
 * Example 1:
 * Input: [[0, 30],[5, 10],[15, 20]]
 * Output: 2
 *
 * Example 2:
 * Input: [[7,10],[2,4]]
 * Output: 1
 */

#include <queue>
/**
 * Algorithm
 *
 * 1. Sort the given meetings by their start time.
 * 2. Initialize a new min-heap and add the first meeting's ending time to the heap. We simply need to keep track of the ending times as that tells us when a meeting room will get free.
 * 3. For every meeting room check if the minimum element of the heap i.e. the room at the top of the heap is free or not.
 * 4. If the room is free, then we extract the topmost element and add it back with the ending time of the current meeting we are processing.
 * 5. If not, then we allocate a new room and add it to the heap.
 * 6. After processing all the meetings, the size of the heap will tell us the number of rooms allocated. This will be the minimum number of rooms needed to accommodate all the meetings.
 */
int minMeetingRooms1(vector<vector<int>>& intervals) {
    if(intervals.size() < 1){
        return 0;
    }

    sort(intervals.begin(), intervals.end());
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(intervals[0][1]);

    int rooms = 1;

    for(int i = 1; i< intervals.size(); i++){
        if(intervals[i][0] < pq.top()){
            rooms++;
        }
        else{
            pq.pop();
        }

        pq.push(intervals[i][1]);
    }

    return rooms;
}

#include <map>
int minMeetingRooms(vector<vector<int>>& intervals) {
    map<int, int> mp;

    for(int i=0; i< intervals.size(); i++) {
        mp[intervals[i][0]] ++;
        mp[intervals[i][1]] --;
    }

    int cnt = 0, maxCnt = 0;
    for(auto it = mp.begin(); it != mp.end(); it++) {
        cnt += it->second;
        maxCnt = max( cnt, maxCnt);
    }

    return maxCnt;
}

