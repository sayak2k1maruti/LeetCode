#include <bits/stdc++.h>
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string part;
        stringstream ss(path);
        
        while (getline(ss, part, '/')) {
            if (part.empty() || part == ".") continue;
            if (part == "..") {
                if (!stack.empty()) stack.pop_back();
            } else {
                stack.push_back(part);
            }
        }
        string result;
        for (const auto& s : stack) {
            result += "/" + s;
        }
        return result.empty() ? "/" : result;
    }
};