#include <cmath>

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0; i < pow(2, n); i++){
            vector<int> subAns;
            for(int j =0; j < n; j++){
                if(i & (1 << j)){
                    subAns.push_back(nums[j]);
                }
            }
            ans.push_back(subAns);
           
	
	
        }
        return ans;
    }
};