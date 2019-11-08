#include "_array.h"

using namespace std;
vector<int> productExceptSelf1(vector<int>& nums) {
    int n=nums.size();
    vector<int> fromBegin(n);
    fromBegin[0]=1;
    vector<int> fromLast(n);
    fromLast[0]=1;

    for(int i=1;i<n;i++){
        fromBegin[i]=fromBegin[i-1]*nums[i-1];
        fromLast[i]=fromLast[i-1]*nums[n-i];
    }

    vector<int> res(n);
    for(int i=0;i<n;i++){
        res[i]=fromBegin[i]*fromLast[n-1-i];
    }
    return res;
}


vector<int> productExceptSelf11(vector<int>& nums) {
    int n=nums.size();
    int fromBegin=1;
    int fromLast=1;
    vector<int> res(n,1);

    for(int i=0;i<n;i++){
        res[i] = res[i] * fromBegin;
        cout << "i " << i << res[i] << "fromBegin " << fromBegin << endl;
        fromBegin = fromBegin * nums[i];
        res[n-1-i] = res[n-1-i] * fromLast;
        fromLast = fromLast * nums[n-1-i];
    }
    return res;
}

vector<int> productExceptSelf(vector<int>& nums) {
    if(nums.empty()){
        return vector<int>{};
    }

    int len = nums.size();
    vector<int> res (len, 1);
    int j = 0;

    for(int i = 0; i< len; i++){
        int left_product = 1;
        int right_product = 1;
        for(int x = 0; x<i; x++){
            left_product = left_product * nums[x];
        }

        for(int x = i+1; x<len; x++){
            right_product = right_product * nums[x];
        }
        cout << "nums[" << i << "] " << nums[i] << " left_product " << left_product << " right_product " << right_product << endl;
        res[j] = left_product*right_product;
        cout << "res[" << j << "]" << res[j] << endl;
        j = j+1;
    }

    return res;

}