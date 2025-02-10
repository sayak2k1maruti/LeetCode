class Solution {
public:
    bool isNonDigit(char c){
        return ! (c >= '0' && c<='9');
    }
    string clearDigits(string s) {
        int n = s.length();
        for(int i = 0;i < n ; i++){
            if(!isNonDigit(s[i])){
                for(int j = i-1; j >= 0 ; j--){
                    if(isNonDigit(s[j])){
                        s[j] = '0';break;
                    }
                }
            }
        }
        string ans = "";
        for(auto c: s){
            if(isNonDigit(c))   ans += c;
        }
        return ans;
    }
};