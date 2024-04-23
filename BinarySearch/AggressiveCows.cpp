#include <algorithm>
#include <climits>

int countCows(vector<int> &stalls, int dist, int cows, int n){
    int count = 1;
    int last = stalls[0];
    
    for(int j= 1; j<n-1;j++){
        if(stalls[j+1] - last >= dist){
            count += 1;
            last = stalls[j+1];
        }
            if (count >= cows) return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int limit = stalls[n-1] - stalls[0];
    int start = 1;
    int end = limit;
    int mid = 0;
    while(start<=end){
        mid = (start + end)/2;
        if(countCows(stalls, mid, k, n)){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return end;
   /* for(int i= 1; i<=limit; i++){
        //int j = 0;
       if(!countCows(stalls, i, k)){
           return (i-1);
       }
    }*/
//return limit;
}