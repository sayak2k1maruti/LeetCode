class Solution {
public:
    unordered_map<char,int> freqCount(string tiles){
        unordered_map<char,int> mp;
        for(auto &c : tiles) mp[c]++;
        return mp;
    }
    int fact(int n){
        int ans = 1;
        for(;n>1;n--)   ans*=n;
        return ans;
    }
    int permutations(unordered_map<char,int> &mp){
        int numerator = 0;
        int denominator = 1;
        for(auto &[key,count] : mp){
            if(count){
                numerator += count;
                denominator *= fact(count);
            }
        }
        return fact(numerator)/denominator;
    }
    int partitions(unordered_map<char,int> &mp,char c){
        if(c > 'Z') return permutations(mp);
        if(! mp[c]) return partitions(mp,c+1);
        
        int possibilities = 0,mem = mp[c];
        for(int i = 0; i <= mem; i++){
            mp[c] = i;
            possibilities += partitions(mp,c+1);
        }
        return possibilities;
    }
    int numTilePossibilities(string tiles) {
        unordered_map<char,int> mp = freqCount(tiles);
        return partitions(mp,'A') - 1;//substracting 1 to handle empty seq
    }
};