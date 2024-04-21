
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        int min_v = INT_MAX;
        while(start <= end){
            int mid  = (start+end)/2;
            if (nums[start] <= nums[end]) {
            min_v = min(min_v, nums[start]);
            break;
        }
            if(nums[start] <= nums[mid]){
                min_v = min(nums[start], min_v);
                start = mid + 1;  
                }
            else{
                min_v = min(nums[mid], min_v);
                end =  mid -1;  
        }
        }

    return min_v;
    }
};