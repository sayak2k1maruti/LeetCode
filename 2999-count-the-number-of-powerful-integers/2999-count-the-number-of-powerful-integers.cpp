#define ll long long
class Solution {
public:
    int i(char& c){
        return c - '0';
    }

    long long nopi(string num,string& s, int limit){
        int l = num.size();
        int sl = s.size();
        int d = l-sl;
        if(sl > l)  return 0;

        bool isSuffTight = false;
        for(int j = 0 ; j < sl; j++){
            if(i(num[d+j]) < i(s[j])){
                isSuffTight = true;
                break;
            }else if(i(num[d+j]) > i(s[j])){
                isSuffTight = false;
                break;
            }
        }

        if(sl == l){
            return isSuffTight ? 0 : 1;
        }
        ll pi = 0;
        for(int j = 0 ; j < d ; j++){
            int ij = i(num[j]);
            if( ij > limit){
                pi += (ll)pow(limit + 1, d - j);
                return pi;
            }else{
                pi += (ll)(ij - 1 + 1) * (ll)pow(limit + 1, d - j - 1);
            }
        }
        
        if(!isSuffTight)    pi++;

        return pi;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        for(auto &c : s){
            if(i(c) > limit)    return 0;
        }
        return nopi(to_string(finish),s,limit) - nopi(to_string(start-1),s,limit);
    }
};