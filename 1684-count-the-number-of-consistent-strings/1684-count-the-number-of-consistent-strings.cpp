#define N 26
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool allowedChar[N] = {false};
        int count = 0;
        for (auto c : allowed)  allowedChar[c-'a']=true;
        
        for (auto word : words){
            bool flag = true;
            for (auto c : word) 
                if (! allowedChar[c-'a']) {flag = false;break;}
            if (flag)   count++;
        }
        return count;
    }
};