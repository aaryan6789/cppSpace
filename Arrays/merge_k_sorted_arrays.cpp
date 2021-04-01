/**
 * LeetCode Medium | CTCI Hard
 * Merge k sorted arrays | Set 2 (Different Sized Arrays)
 * Given k sorted arrays of possibly different sizes, merge them and print the sorted output.
 *
 * Examples:
 * Input: k = 3
 *       arr[][] = { {1, 3},
 *                   {2, 4, 6},
 *                   {0, 9, 10, 11}} ;
 * Output: 0 1 2 3 4 6 9 10 11
 *
 * Input: k = 2
 *       arr[][] = { {1, 3, 20},
 *                   {2, 4, 6}} ;
 * Output: 1 2 3 4 6 20
 */

/**
 * Using Heap Data Structure
 * The time complexity of heap based solution is O(N Log k).
 *
 * 1. Create an output array.
 * 2. Create a min heap of size k and insert 1st element in all the arrays into the heap
 * 3. Repeat following steps while priority queue is not empty.
 *     a) Remove minimum element from heap (minimum is always at root) and store it in output array.
 *     b) Insert next element from the array from which the element is extracted. If the array doesn’t have any more elements, then do nothing.
 */
#include "_array.h"
#include <queue>

// A pair of pairs, first element is going to store value,
// second element index of array and third element index in the array.
// Pair<value_in_array, <array_index, index_in_array>>
typedef pair<int, pair<int, int>> ppi;

vector<int> mergeKSortedArrays(vector< vector<int> >& A){       // 2D vector given
    // Create a Result Vector
    vector<int> result;

    // Create a min heap with k heap nodes.
    // Every heap node has first element of an array.
    priority_queue<ppi, vector<ppi>, greater<ppi> > minHeap;

    // Push 1st element of all the arrays to the minHeap
    // 2D Vector - Row = A.size() , Col = A[i].size() where col size can vary
    for(int i =0; i< A.size(); i++){
        minHeap.push({A[i][0], {i, 0}});        // Pair is made as {v1, v2} --> {vi, {v1, v2}}
    }

    // Now one by one get the minimum element from min heap and replace it
    // with next element of its array
    while(!minHeap.empty()){
        ppi curr = minHeap.top();       // Gives you an element
        minHeap.pop();                  // Returns nothing

        int i = curr.second.first;      // i = Array Number in the 2D array list
        int j = curr.second.second;     // j = Index in the array number

        result.push_back(curr.first);   // Push the min element first

        if(j+1 < A[i].size()){                      // The next element belongs to same array as current.
            minHeap.push( { A[i][j+1], { i, (j+1) }});
        }
    }
    return result;
}


// Merge K Sorted Arrays
vector<int> mergeKSortedArrays1(vector<vector<int>>& A){
    cout << "Merge " << A.size() << " Arrays" << endl;
    vector<int> res = {};

    if(A.size() == 0){
        return res;
    }

    // Make a Min Heap of Vector
    typedef vector<int> vi;     // {item, i, j}
    priority_queue<vi, vector<vi>, greater<vi>> minHeap;

    for(int i = 0; i<A.size(); i++){
        minHeap.push({A[i][0], i, 0});
    }

    while(!minHeap.empty()){
        vector<int> top = minHeap.top();    minHeap.pop();
        int x = top[1];
        int y = top[2];
        res.push_back(top[0]);

        // Push the next item on the heap from that vector
        if(y+1 < A[x].size()){
            minHeap.push({A[x][y+1], x , y+1});
        }
    }

    return res;
}



/**
 * Algo 2 - Combine and sort
 * - Add all the arrays together and then sort them
 * - O(nk Lognk)
 */



