/*
Author : Sayak Das
Link : https://leetcode.com/problems/longest-common-prefix/submissions/
Date  : 8Oct2022
*/
#include "bits/stdc++.h"
using namespace std;
class Solution {
private:
    int findMinLen(vector<string>& strs){
        int n = INT_MAX;
        for(auto it : strs){
            n = min(n , (int)it.length());
        }     
        return n;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
         int n = findMinLen(strs);
         string ans = "";
         bool flag = true;
         for(int i = 0 ; i < n && flag ; i ++){
            char c = strs[0][i];
            for(string it : strs){
                if(c != it[i]){
                    flag = false;
                }
            }
            if(flag)
                ans += c;
         }
         return ans;
    }
};
int main(){
    Solution sol;
    int n ;
    cin >> n;
    vector <string> strs(n);
    for(int i =0 ; i < n ; i++){
        cin >> strs[i];
    }
    cout << sol.longestCommonPrefix(strs) << endl;
    return 0;
}