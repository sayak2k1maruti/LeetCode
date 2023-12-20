class Solution {
public:
    string generateClose(int n){
        string s;
        for (int i = 0; i<n; i++)   s += ")";
        return s;
    }
    void generateParenthesis(string s,int open,int close,vector<string> &ans){
        //open -> number of '(' needed to be add
        //close -> number of ')' needed to be add, i.e total number of open ( till now
        if(!open){
            ans.push_back(s + generateClose(close));
            return;
        }
        generateParenthesis(s+"(",open-1,close+1,ans);
        if(close){
            generateParenthesis(s + ")",open,close-1,ans);
        }
    } 
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generateParenthesis("(",n-1,1,ans);
        return ans;
    }
};