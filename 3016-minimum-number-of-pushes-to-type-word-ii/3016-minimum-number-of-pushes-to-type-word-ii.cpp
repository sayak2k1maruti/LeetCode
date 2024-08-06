class Solution {
public:
    int minimumPushes(string word) {
        int charCount[26] = {0};
        vector<int> charOccurances;
        for (auto c : word) charCount[c-'a']++;
        for(int i = 0 ; i < 26 ; i ++)  
            if (charCount[i])
                charOccurances.push_back(charCount[i]);
        sort(charOccurances.begin(),charOccurances.end(),greater<int>());
        int keyCount = 0;
        int numOfPress = 0;

        for (auto count : charOccurances){
            numOfPress += count * ((++keyCount-1)/8 + 1);
        }
        return numOfPress;
    }
};