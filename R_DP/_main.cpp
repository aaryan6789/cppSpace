#include "_r_dp.h"
#include <iostream>

using namespace std;
int main() {
    cout << "Recursion DP" << endl;
    vector<int> A {0, 1, 2, 3, 4, 5, 6};

    sumArray(A);

    for(auto& v: A){
        cout << v << " " ;
    }
    cout << endl;

    vector<string> str = generateParenthesis2(3);
    for(auto& s : str){
        cout << s << " ";
        cout << endl;
    }
    cout << endl;

    cout << countWaysDP(2) << endl;
    cout << countWaysDP(3) << endl;
    cout << countWaysDP(4) << endl;

    cout << countWaysR(3) << endl;
    cout << countWaysR(4) << endl;

    cout << "5 " << countWaysR(5) << endl;
    cout << "6 " << countWaysDP(6) << endl;


    vector<int> AA(3, 3);
    for(auto& i : AA){
        cout << i << endl;
    }



    cout << endl;


}
