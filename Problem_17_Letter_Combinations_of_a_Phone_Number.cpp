/*
Author : Sayak Das
Link : https://leetcode.com/problems/longest-common-prefix/submissions/
Date  : 8Oct2022
*/
#include "bits/stdc++.h"
using namespace std;
class Solution {
private:
    map <char , string > keymap{
        {'2' , "abc"},
        {'3' , "def"},
        {'4' , "ghi"},
        {'5' , "jkl"},
        {'6' , "mno"},
        {'7' , "pqrs"},
        {'8' , "tuv"},
        {'9' , "wxyz"},
    };
public:
    void lc(string &digits , int n , vector <string> &arr , string ans){
        if(n <= 0){
            if(ans.length())
                arr.push_back(ans);
            ans = "";
            return ;
        }
        string key = keymap[digits[n-1]];
        for(char c : key){
            lc(digits , n-1 , arr , c + ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector <string> arr;
        lc(digits , digits.length() , arr , "");
        return arr;
    }
};
int main(){
    Solution sol;
    string digits;
    cin >> digits;
    for(auto it : sol.letterCombinations(digits) ){
        cout << it << endl;
    }
    return 0;
}