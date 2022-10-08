/*
Author : Sayak Das
Link : https://leetcode.com/problems/longest-common-prefix/submissions/
Date  : 8Oct2022
*/
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        int ans , closest=INT_MAX;
        for(int i = 0 ; i < nums.size() ; i++){
            int k = target - nums[i];
            int l = i+1;
            int r = nums.size() - 1;
            while( l < r){
                int sum = nums[l] + nums[r];
                if(abs(target - sum - nums[i]) < closest){
                    closest = abs(target - sum - nums[i]);
                    ans = sum + nums[i];
                }
                if(sum > k){
                    r--;
                }else if(sum < k){
                    l++;
                }else{
                    //i.e. sum == k
                    return target;
                }
            }
        }
        return ans;
    }
};
int main(){
    Solution sol;
    int n , t;
    cin >> n >> t;
    vector <int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    cout << sol.threeSumClosest(arr , t) << endl;
    return 0;
}