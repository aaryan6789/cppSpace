#include "_matrix.h"

/** 957. Prison Cells After N Days | LeetCode M
 * There are 8 prison cells in a row, and each cell is either occupied or vacant.

Each day, whether the cell is occupied or vacant changes according to the following rules:
Rule: 

If a cell has two adjacent neighbors that are both occupied or both vacant, 
then the cell becomes occupied.
Otherwise, it becomes vacant.

(Note that because the prison is a row, the first and the last cells in the row 
can't have two adjacent neighbors.)

We describe the current state of the prison in the following way: 
cells[i] == 1 if the i-th cell is occupied, 
cells[i] == 0.

Given the initial state of the prison, 
return the state of the prison after N days (and N such changes described above.)

Example 1:
Input: cells = [0,1,0,1,1,0,0,1], N = 7
Output:        [0,0,1,1,0,0,0,0]

Explanation: 
The following table summarizes the state of the prison on each day:
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]

Example 2:

Input: cells = [1,0,0,1,0,0,1,0], N = 1000000000
Output: [0,0,1,1,1,1,1,0]
 

Note:

cells.length == 8
cells[i] is in {0, 1}
1 <= N <= 10^9
 */

// Algorithms:
// 1. Same as (enter question)
// 2. Make a auxiliary vector to keep the next state from the prev state
// 3. Then we can replace the prev state from the next vector.
// We perform the simulation untill we find a cycle. Note that the cycle can start after the first simulation (f_c), since edge cells can be occupied initially.

// Note that this solution does not rely on the cycle size (which can be 1, 7, or 14 for 8 cells). Therefore, it works for arbitrary number of cells, not just 8.
vector<int> prisonAfterNDays2(vector<int>& c, int N) {
    vector<int> f_c;
    vector<int> next_c(c.size(), 0);
    int cycle = 0;
    
    while(N-- > 0){
        for(int i = 1; i<7; i++){
            if((c[i-1] == 0 && c[i+1] == 0) ||
               (c[i-1] == 1 && c[i+1] == 1)){
                   next_c[i] = 1;
            }
            else {
                next_c[i] = 0;
            }
        }
        
        // Cache the 1st Days setting and then repeat it in cycles if thats the same
        if (cycle == 0) 
            f_c = next_c;
        else if (next_c == f_c) 
            N = N%cycle;
        
        c = next_c;
        cycle++;
    }

    return c;
}


/// The Below code is just the same as the above

vector<int> prisonAfterNDays3(vector<int>& c, int N) {
    vector<int> f_c;
    vector<int> next_c(c.size(), 0);
    int cycle = 0;
    
    while(N-- > 0){
        for (auto i = 1; i < c.size() - 1; ++i) 
            next_c[i] = c[i - 1] == c[i + 1];
        if (cycle == 0) 
            f_c = next_c;
        else if (next_c == f_c) 
            N = N%cycle;
        
        c = next_c;
        cycle++;
    }
        
    return c;
}
