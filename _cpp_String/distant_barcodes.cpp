
/** DISTANT BARCODES | LC M| 1054 | 
 * PreReq : Reorganize Strings
 * In a warehouse, there is a row of barcodes, where the i-th barcode is barcodes[i].
Rearrange the barcodes so that no two adjacent barcodes are equal.  You may return any answer, and it is guaranteed an answer exists.


Example 1:
Input: [1,1,1,2,2,2]
Output: [2,1,2,1,2,1]

Example 2:
Input: [1,1,1,1,2,2,3,3]
Output: [1,3,1,3,2,1,2,1]
 
Note:
1 <= barcodes.length <= 10000
1 <= barcodes[i] <= 10000
 */
#include "_string.h"
#include <queue>
using ppi = pair<int, int>;
vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    if(barcodes.size() <= 2){
        return barcodes;
    }
    
    unordered_map<int, int> map;
    
    for(int n : barcodes){
        map[n]++;
    }
    
    priority_queue<ppi> maxHeap;
    
    for(auto &kv : map){        //<--- & is critical for keeping the actual value
        maxHeap.push({kv.second, kv.first});
    }
    
    vector<int> res;
    while(maxHeap.size() >= 2) {
        ppi a = maxHeap.top() ; maxHeap.pop();
        ppi b = maxHeap.top() ; maxHeap.pop();
        
        res.push_back(a.second);
        a.first--;
        
        res.push_back(b.second);
        b.first--;
            
        if(a.first != 0) maxHeap.push(a);
        if(b.first != 0) maxHeap.push(b);
    }
    
    if(!maxHeap.empty()){
        res.push_back(maxHeap.top().second);
    }
    
    return res;
}