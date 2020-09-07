#include "_r_dp.h"

int sum(unsigned int n){
    if(n < 0){
        return 0;
    }

    if(n == 1 || n == 0){
        return n;
    }

    return (n + sum(n-1));
}

void sumArray(vector<int>& A){
    for(int i = 0 ; i< A.size(); i++){
        A[i] = sum(i);
    }

    return;
}