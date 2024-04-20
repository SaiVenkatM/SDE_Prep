#include <bits/stdc++.h>
using namespace std;


int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    /*int result;
    int count=0;
    for (int i=0; i<a.size(); i++){
        for(int j=0; j<a.size();j++){
            result = 0;
            for (int k=i; k<=j;k++){
                result ^= a[k];
            }
            if (result == b){
                count += 1;
            }
        }
    }
    return count;*/
    //Better Approach
   /* int result = 0;
    int count = 0;
    for(int i=0; i<a.size(); i++){
        result = 0;
        for(int j = i; j<a.size();j++){
            result ^= a[j];
            if (result == b){
                count += 1;
            }
        }
    }
  return count;*/
  //Optimal Approach
  int n = a.size();
  int xr = 0;
  unordered_map<int ,int> XOR;
  XOR[xr]++;
  int count = 0;
  for(int i=0; i<n; i++){
      xr = xr^a[i];
      int x = xr ^ b;
      count += XOR[x];
      XOR[xr]++;
  }
  return count;

}