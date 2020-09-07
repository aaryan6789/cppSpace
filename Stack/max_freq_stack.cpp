#include "_stack.h"
/**
LeetCode H | 895. Maximum Frequency Stack | Design | Hash Map | Stack
Implement FreqStack, a class which simulates the operation of a stack-like data structure.

FreqStack has two functions:

push(int x), which pushes an integer x onto the stack.
pop(), which removes and returns the most frequent element in the stack.
Note: If there is a tie for most frequent element, the element closest to the top of the stack is removed and returned.

Example 1:
Input: ["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
       [[],[5],[7],[5],[7],[4],[5],[],[],[],[]]

Output: [null,null,null,null,null,null,null,5,7,5,4]

Explanation:
After making six push operations, the stack is [5,7,5,7,4,5] from bottom to top.  
Then:
pop() -> returns 5, as 5 is the most frequent.
The stack becomes [5,7,5,7,4].

pop() -> returns 7, as 5 and 7 is the most frequent, but 7 is closest to the top.
The stack becomes [5,7,5,4].

pop() -> returns 5.
The stack becomes [5,7,4].

pop() -> returns 4.
The stack becomes [5,7].

Note:

Calls to FreqStack.push(int x) will be such that 0 <= x <= 10^9.
It is guaranteed that FreqStack.pop() won't be called if the stack has zero elements.
The total number of FreqStack.push calls will not exceed 10000 in a single test case.
The total number of FreqStack.pop calls will not exceed 10000 in a single test case.
The total number of FreqStack.push and FreqStack.pop calls will not exceed 150000 across all test cases. */

/**
Approach: 
1. Maintaining two Maps, 
   one is frequency Map which maps elements to their frequencies and 
   other is stacks which maps all the element with same frequency in one group (Stack).

FrequencyStack has 2 functions:
push(int x): 
1. map the element (x) with frequency Map and 
2. update the maxfreq variable ( i.e. holds the maximum frequency till now ). 
3. stacks maintains a stack which contains all the elements with same frequency.

pop(): 
1. First get the maxfreq element from stacks map and then 
2. decrement the frequency of the popped element. 
After popping, if the stack becomes empty then decrement the maxfreq.
*/

class FreqStack {
    unordered_map<int, stack<int>> stacks;
    unordered_map<int, int> map;
    int max_freq;
    
public:
    FreqStack() {
        max_freq = 0;
    }
    
    void push(int x) {
        map[x]++;       // Increment the frequency of the element
        
        int freq = map[x];
        stacks[freq].push(x);
        
        // Get the max freq so far
        max_freq = max(max_freq, freq);
    }
    
    int pop() {
        int ret = stacks[max_freq].top();    stacks[max_freq].pop();
        
        if(stacks[max_freq].size() == 0){
            max_freq--;
        }
        
        // Reduce the Freq of the returned item
        map[ret]--;
        return ret;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */