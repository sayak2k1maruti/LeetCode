/*
Author : Sayak Das
Link : https://leetcode.com/problems/longest-common-prefix/submissions/
Date  : 8Oct2022
*/
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, long target) {
        set <vector<int>> s;
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < nums.size() ; i++){
            long a = nums[i];
            for(int j = i+1; j < nums.size() ; j++){
                long b = nums[j];
                long l = j + 1 ; 
                long r = nums.size() - 1;
                long k = target - a - b;
                while( l < r){
                    long c = nums[l];
                    long d = nums[r];
                    long sum = c + d;
                    if(sum == k){
                        s.insert(vector<int>{(int)a,(int)b,(int)c,(int)d});
                        l++;
                    }else if(sum > k){
                        r--;
                    }else{
                        l ++;
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for(auto it : s){
            ans.push_back(it);
        }      
        return ans;
    }
};
int main(){
    Solution sol;
    int n,t;
    cin >> n >> t;
    vector <int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i]; 
    }
    for(auto it : sol.fourSum(arr , t)){
        for(int i : it){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}