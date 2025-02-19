char arr[] = {'a','b','c'};
class Solution {
public:
    
    string generate(string s,int n,int &count,int k){
        string x;
        if (s.length() == n) {
            count++;
            if (count == k) return s;
            return "";
        }

        for(int i = 0 ;i < 3 ;i++){
            if((s.length()==0) || (arr[i] != s[s.length()-1]))
            {x = generate(s+arr[i],n,count,k);
            if(x.length()) return x;}
        }
        return "";
    }
    string getHappyString(int n, int k) {
        int count = 0;
        string ans = "";
        ans = generate(ans,n,count,k);
        return ans;
    }
};