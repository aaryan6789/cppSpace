#include "_pq.h"

void printPQ(priority_queue<int> pq){
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
}

void printPQ2(priority_queue<int, vector<int>, greater<int>> pq){
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
}

template <class T>
void printPQT(T pq){
    cout << endl;
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
}


// For Priority Queue (custom) use a Decl Type
// this is an strucure which implements the operator overlading 
struct mycomp{
    bool operator()(const int& lhs, const int& rhs){
        return lhs < rhs;       // lhs > rhs ->For minHeap
        // return "true" if "lhs" is ordered before "rhs", for example: 10, 20
    }
};

// For Sorting use a Functor

void priority_queue_basics() {
    cout << "PRORITY QUEUE BASICS " << endl;
    
    vector<int> a{1, 4, 3, 6, 9, 8, 13, 11};

    // priority_queue<int> maxHeap(a.begin(), a.end());
    // printPQ(maxHeap);

    priority_queue<int, vector<int>, greater<int>> minHeap(a.begin(), a.end());
    printPQ2(minHeap);

    priority_queue<int, vector<int>, mycomp> minHeap2;
    minHeap2.push(10);
    minHeap2.push(20);
    minHeap2.push(15);
    // minHeap2.push(30);
    printPQT(minHeap2);

    
    


}