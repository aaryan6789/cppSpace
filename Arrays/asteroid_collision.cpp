#include "_array.h"
using namespace std;

/**LEETCODE M | GOOG LYFT AMZN
 * We are given an array asteroids of integers representing asteroids in a row.
For each asteroid, the absolute value represents its size, and the sign
represents its direction (positive meaning right, negative meaning left).
Each asteroid moves at the same speed.
Find out the state of the asteroids after all collisions.
If two asteroids meet, the smaller one will explode.
If both are the same size, both will explode.
Two asteroids moving in the same direction will never meet.

Example 1:
Input:
asteroids = [5, 10, -5]
Output: [5, 10]
Explanation:
The 10 and -5 collide resulting in 10.  The 5 and 10 never collide.

Example 2:
Input:
asteroids = [8, -8]
Output: []
Explanation:
The 8 and -8 collide exploding each other.

Example 3:
Input:
asteroids = [10, 2, -5]
Output: [10]
Explanation:
The 2 and -5 collide resulting in -5.  The 10 and -5 collide resulting in 10.

Example 4:
Input:
asteroids = [-2, -1, 1, 2]
Output: [-2, -1, 1, 2]
Explanation:
The -2 and -1 are moving left, while the 1 and 2 are moving right.
Asteroids moving the same direction never meet, so no asteroids will meet each other.

Note:
The length of asteroids will be at most 10000.
Each asteroid will be a non-zero integer in the range [-1000, 1000].. */

// {1, 2, -2, 1} --> {1, 1}
// {-1, -2, 2, 1}


vector<int> asteroidCollision(vector<int>& asteroids){
    // Using Stack : Vector as a stack as Stack is LIFO (Vector: push_back, back, pop_back )
    vector<int> s;

    for(auto& a : asteroids){
        // Push on Stack
        if( s.empty()    ||         // If Stack is empty
            s.back() < 0 ||         // OR If the Top of stack is -ve
            a > 0){                 // OR If a +ve asteroid
                s.push_back(a);
        }
        else{
            while( !s.empty() && s.back() > 0 && abs(a) > s.back())
                s.pop_back();

            if(s.empty() || s.back() < 0){
                s.push_back(a);
            }
            else if(abs(a) == s.back()){
                s.pop_back();
            }
        }

        return s;
    }
}


#include <stack>
vector<int> asteroidCollision2(vector<int>& asteroids) {
    stack<int> st;
    for(int& m : asteroids) {
        if(m >= 0) {
            st.push(m);
        }
        else {
            while(!st.empty() && st.top() > 0 && st.top() < -m) {
                st.pop();
            }

            if(!st.empty() && st.top() == -m) {
                st.pop();
                continue;       // Go to next iteration
            }

            if(st.empty() || st.top() < 0) {
                st.push(m);
            }
        }
    }

    vector<int> res(st.size(), 0);
    for(int i=st.size()-1; i>=0; i--) {
        res[i] = st.top();
        st.pop();
    }
    return res;
}