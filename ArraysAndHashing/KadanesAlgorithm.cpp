#include <vector>
#include <climits>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN;
        int prevSum = 0;
        /*int j = 0;
        int i = 0;
        while (j < nums.size()) {
           if (nums[j] > prevSum + nums[j]){
            prevSum = nums[j];
            i = j;
            j += 1;
           }
           else{
            prevSum += nums[j];
            j+= 1;
           }
            if(result < prevSum){
                result = prevSum;
            }
            
            }
            
            return result;*/
        for (auto i: nums){
            prevSum += i;
            result = max(prevSum, result);
            if (prevSum <=0){
                prevSum = 0;
            }
        }
        return result;
        }
       // cout<<result<<endl;
    
};