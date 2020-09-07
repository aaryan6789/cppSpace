/* main.cpp  * Created on: Aug 12, 2018 * Author: Harsh */
#include <iostream>
#include <utility>

#include <vector>
#include "_array.h"

using namespace std;

void printVector(vector<int>& vec){
    for(auto& item : vec){
        cout << item << " ";
    }
    cout << endl;
}


int main(){

    vector<int> A;

    for (int i = 1; i <= 5; i++)
        A.push_back(i);

    cout << "Output of begin and end: ";
    for (auto i = A.begin(); i != A.end(); ++i)
        cout << *i << " ";

    std::cout << "Main" << endl;
    twoSum(A, 6);

    maxArea(A);

    vector<int> B = {1, 3, -5, 2, 7};
    findPairs(B, 2);
    findPairs2(B, 2);

    vector<int> C = {1};
    majorityElement2(C);

    peaks_and_valleys(B);
    printVector(B);

    vector<int> D = {1,1,2, 2, 3,3, 4,4 ,6, 6,5,5, 7};
    cout << singleNumberSet(D) << endl;

    sum_close_to_zero(A);


    kClosestElementToVal(D, 3);

    printArray(B);
    cout << checkZeroSubArray(B) << endl;

    printZeroSumSubArray(B);
    printArray(A);
    cout << "4th Largest item = " << FindKthLargest2(A, 4) << endl;

    vector<int> pr{1,2,3,4};
    vector<int> res = productExceptSelf(pr);
    printArray(res);

    smallestK(pr, 2);

    vector<int> rpn{-1,-2,-3,-4, 5 ,6, 7, 9};
    cout << "regarrange_pos_neg" << endl;
    regarrange_pos_neg(rpn);
    printArray(rpn);

    vector<int> AA {1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << binarySearchSortedRotated(AA, 4);

    // Hello
    // World
}