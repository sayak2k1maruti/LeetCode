/*
Author : Sayak Das
Link : https://leetcode.com/problems/longest-common-prefix/submissions/
Date  : 8Oct2022
*/
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int rti(string &s , int n){
        if(n == 0){
            return 0;
        }
        if(s[n-1] == 'M'){
            if(n-2 >= 0 && s[n-2] == 'C'){
                return 900 + rti(s,n-2);
            }else{
                return 1000 + rti(s , n-1);
            }
        }else if(s[n-1] == 'D'){
            if(n -2 >= 0 && s[n-2] == 'C'){
                return 400 + rti(s,n-2);
            }else{
                return 500 + rti(s , n-1);
            }
        }else if(s[n-1] == 'C'){
            if(n -2 >= 0 && s[n-2] == 'X'){
                return 90 + rti(s,n-2);
            }else{
                return 100 + rti(s , n-1);
            }
        }else if(s[n-1] == 'L'){
            if(n -2 >= 0 && s[n-2] == 'X'){
                return 40 + rti(s,n-2);
            }else{
                return 50 + rti(s , n-1);
            }
        }else if(s[n-1] == 'X'){
            if(n -2 >= 0 && s[n-2] == 'I'){
                return 9 + rti(s,n-2);
            }else{
                return 10 + rti(s , n-1);
            }
        }else if(s[n-1] == 'V'){
            if(n -2 >= 0 && s[n-2] == 'I'){
                return 4 + rti(s,n-2);
            }else{
                return 5 + rti(s , n-1);
            }
        }else if(s[n-1] == 'I'){
            return 1 + rti( s , n-1);
        }
        return INT_MAX;
    }
    int romanToInt(string s) {
          return rti(s , s.length());
    }
};
int main(){
    int t;
    cin >> t;
    Solution sol;
    for(;t--;){
        string s;
        cin >> s;
        cout <<  sol.romanToInt(s) << endl;
    }
    return 0;
}