class Solution {
public:
    string reverseParentheses(string s) {
        int left = 0;
        int right = 0;
        for (int i = 0 ; i < s.length(); i++){
            if (s[i] == '(')    {left = i;}
            else if(s[i]==')')  {right=i;break;}
        }
        string left_s = left!=0 ? s.substr(0,left) : "";
        string right_s = right+1<s.length() ? s.substr(right+1,s.length()-right+1) : "";
        if (right){
            string innr = s.substr(left+1,right-left-1);
            reverse(innr.begin(),innr.end());
            return reverseParentheses(left_s + innr + right_s);
        }
        return s;
    }
};