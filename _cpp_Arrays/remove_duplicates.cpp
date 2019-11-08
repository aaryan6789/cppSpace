#include "_array.h"

int removeDuplicates(vector<int>& nums){
    if (nums.size()<=1)
        return nums.size();

    // Using Iterator
    // vector<int>::iterator it;
    // for(it=nums.begin()+1;it!=nums.end();it++){
    //     if((*it)==*(it-1))
    //         it=nums.erase(it-1);
    // }
    int j = 0;
    for(int i = 0; i< nums.size()-1; i++){
        if(nums[i] != nums[i+1]){
            nums[j++] = nums[i];
        }
    }
    nums[j++] = nums[nums.size()-1];

    return j;
}


int removeDuplicatesSTL(vector<int>& nums) {
    nums.erase( unique( nums.begin(), nums.end() ), nums.end() );
    return nums.size();
}