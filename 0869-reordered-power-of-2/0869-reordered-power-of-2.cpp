class Solution {
public:
    bool isPowerofTwo(int n) {
        return ((n & (~(n-1))) == n);
    }
    void allPermuattion(int index, string &s,vector<string> &ans) {
        if (index == s.size()) {
            if (s[0] != '0') ans.push_back(s);
            return;
        }
        for (int i = index; i < s.size(); i++) {
            swap(s[index], s[i]);
            allPermuattion(index + 1, s, ans);
            swap(s[index], s[i]);
        }
    }
    string int2str(int n){
        string ans = "";
        for(;n != 0; n/=10){
            ans = char('0' + (n % 10)) + ans;
            //cout << ans <<' ' <<(char)(n%10+'0') << endl;
        }
        return ans;
    }
    int str2int(string s){
        int n = 0;
        for(auto c : s){
            n = n*10 + (c-'0');
        }
        return n;
    }
    bool reorderedPowerOf2(int n) {
        vector <string> allPermute;
        string os = int2str(n);
        //cout << os << endl;
        if(os.length() < 2){
            return true;
        }
        allPermuattion(0,os,allPermute);
        //for(auto s :allPermute) cout << s << endl;
        for (auto sn : allPermute){
            if (isPowerofTwo(str2int(sn)))
                return true;
        }
        return false;
    }
};