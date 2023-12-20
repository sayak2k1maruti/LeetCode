#include <bits/stdc++.h>
class Solution {
public:
    bool isValid(string s) {
        stack<int> arr;
        map<char,char> mp;
        mp[')'] = '(';
        mp['}'] = '{';
        mp[']'] = '[';
        for (auto c : s){
            if (arr.empty())    arr.push(c);
            else if(c == '(' || c == '{' || c == '[')   arr.push(c);
            else if(mp[c] == arr.top()) arr.pop();
            else return false;
        }
        return arr.empty();
    }
};