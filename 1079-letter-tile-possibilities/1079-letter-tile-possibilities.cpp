class Solution {
public:
    void freqCount(string tiles,int* mp){
        //unordered_map<char,int> mp;
        for(auto &c : tiles) mp[c-'A']++;
    }
    int fact(int n){
        int ans = 1;
        for(;n>1;n--)   ans*=n;
        return ans;
    }
    int permutations(int* mp){
        int numerator = 0;
        int denominator = 1;
        for(int i='A';i<='Z';i++){
            int count = mp[i-'A'];
            if(count){
                numerator += count;
                denominator *= fact(count);
            }
        }
        return fact(numerator)/denominator;
    }
    int partitions(int* mp,char c){
        if(c > 'Z') return permutations(mp);
        if(! mp[c-'A']) return partitions(mp,c+1);
        
        int possibilities = 0,mem = mp[c-'A'];
        for(int i = 0; i <= mem; i++){
            mp[c-'A'] = i;
            possibilities += partitions(mp,c+1);
        }
        return possibilities;
    }
    int numTilePossibilities(string tiles) {
        //unordered_map<char,int> mp = freqCount(tiles);
        int mp[26] = {0};
        freqCount(tiles,mp);
        return partitions(mp,'A') - 1;//substracting 1 to handle empty seq
    }
};