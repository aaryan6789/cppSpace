#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

void printArray(vector<int>& stream){  
    for (int i = 0; i < stream.size(); i++)
        cout << stream[i] << " ";  
    cout << endl;
}


// ReserVoir Sampling

// Select K items from a Stream of N items


// Method 1 : using hash Map to find out if an element is already in the result or not

// Method 2 : Reservoir Sampling
vector<int> selectKItems(vector<int>& stream, int n, int k){
    vector<int> res;

    // 1. Push the 1st K elements on the Array
    for(int i = 0; i<k ; i++){
        res.push_back(stream[i]);
    }

    // IMPORTANT STEP:
    // Use a different seed value so that we don't get  
    // same result each time we run this program 
    srand(time(nullptr));

    // 2. Now Generate a random number
    for(int i = k; i<n; i++){
        int j = rand() % (i+1);
        cout << "Rand = " << j << endl;

        // If j is less than k i.e if itn the range of 0 to k then replace the num
        if(j < k){
            res[j] = stream[i];
        }
    }

    printArray(res);
    return res;
}



int main() {
    vector<int> stream = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};  
    int n = sizeof(stream)/sizeof(stream[0]);
    int k = 5;
    selectKItems(stream, n, k);  
    return 0;
}