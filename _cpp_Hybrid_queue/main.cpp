#include <queue>
#include <iostream>
using namespace std;

struct node{
    int data;
    int deadline;
    node(int x, int y) : data(x), deadline(y) {}
};

class HybridQueue{

private:
    // EDF Queue
    priority_queue<int> edf;    // Top is the earliest deadline first

    // FIFO Queue
    deque<int> fifo;
};


int main() {
    deque<int> dq;

    deque<node*> dqn;
    node* temp = new node(3, 4);
    dqn.push_back(temp);
    node* temp2 = new node(4, 5);
    dqn.push_back(temp2);

    dq.push_back(1);
    dq.push_front(2);

    for(auto& i : dq){
        cout << i << " ";
    }
    cout << endl;

    for(auto& it : dqn){
        cout << it->data << " " << it->deadline << endl;
    }

    cout << endl;
}