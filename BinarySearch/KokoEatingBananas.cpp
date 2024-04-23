#include <algorithm>
#include <cmath>


class Solution {
public:
    /*int calculateTotalHours(vector<int> &v, int hourly) {
    long long totalH = 0;
    int n = v.size();
    //find total hours:
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int minV = INT_MAX;
        int maxV = INT_MIN;
        int target = INT_MAX;
        for(auto i: piles){
            maxV = max(maxV, i);
            minV = min(minV, i);
        }
        for(int i = 1; i<=maxV; i++){
            double hours = 0;
            hours += calculateTotalHours(piles, i);
            //cout<<hours<<endl;
            if (hours <= h) {
                target = min(target, i);
                //cout<<"Inside target "<< target <<" speed" <<endl;
            }

        }
        return target;
    }*/
    long long int calculateTotalHours(vector<int> &v, int hourly) {
        long long int totalH = 0; 
        int n = v.size();
        
        for (int i = 0; i < n; i++) {
            totalH += (long long int)ceil((double)(v[i]) / (double)(hourly));
        }
        return totalH;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int minV = INT_MAX; 
        long long int maxV = INT_MIN; 
        long long int target = INT_MAX; 
        for(auto i: piles){
            maxV = max(maxV, (long long int)i); 
            minV = min(minV, (long long int)i); 
        }
        int start = 1;
        long long int end = maxV; 
        while(start <= end){
            long long int mid = (start + end)/2; 
            long long int hours = 0; 
            hours += calculateTotalHours(piles, mid);
            if (hours > h){
                start = mid + 1;
            }
            else {
                end = mid - 1;
                target = min(target, mid);
            }
        }
        return target;
    }
};

