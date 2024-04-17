#include <algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }
        if(i == -1){
            //cout<<"could not find sort"<<endl;
            reverse(nums.begin(), nums.end());
            return;

        }
        int j = nums.size()-1;
        while(nums[j] <= nums[i]){
            j -= 1;
        }
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());

    }
};