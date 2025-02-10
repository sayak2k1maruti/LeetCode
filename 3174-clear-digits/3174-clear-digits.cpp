class Solution {
public:
    bool isNonDigit(char c){
        return ! (c >= '0' && c<='9');
    }
    void markNearestNonDigitLeft(string &s,int index){
        for(int i = index-1; i>=0; i--){
            if(isNonDigit(s[i])){
                s[i] = '0';
                return;
            }
        }
    }
    string deleteAllNonDigits(string& s){
        string ans = "";
        for(auto &c: s){
            if(isNonDigit(c))   ans += c;
        }
        return ans;
    }
    string clearDigits(string s) {
        int n = s.length();
        for(int i = 0;i < n ; i++){
            if(!isNonDigit(s[i])){
                markNearestNonDigitLeft(s,i);
            }
        }

        return deleteAllNonDigits(s);
    }
};