#define N 26
class Solution {
public:
    string getUniqueCharStr(string& s){
        bool chars[N] = {false};
        string ucs = "";
        for(auto c : s) chars[c-'a'] = true;
        for(int i =0 ; i < N ; i++)
            if (chars[i])   ucs += (char)('a' + i);
        return ucs;
    }
    int similarPairs(vector<string>& words) {
        int pairsCount = 0;
        map<string,int> wordsMap;
        for(auto word : words){
            wordsMap[getUniqueCharStr(word)]++;
        }
        for(auto it : wordsMap){
                pairsCount += it.second * (it.second - 1)/2;
        }
        return pairsCount;
    }
};