class Solution {
public:
    bool isPowerofTwo(int n) {
        return ((n & (~(n-1))) == n);
    }
    void allPermuattion(int index, string &s,bool &flag) {
            if(! flag){
                if (index == s.size()) {
                    if ((s[0] != '0')){
                        if(isPowerofTwo(str2int(s)))    
                            flag = true;
                    }
            return;
            }
        }
        for (int i = index; i < s.size(); i++) {
            swap(s[index], s[i]);
            allPermuattion(index + 1, s,flag);
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
        string os = int2str(n);
        bool flag = false;
        //cout << os << endl;
        if(os.length() < 2){
            return true;
        }
        allPermuattion(0,os,flag);
        //for(auto s :allPermute) cout << s << endl;
        
        return flag;
    }
};