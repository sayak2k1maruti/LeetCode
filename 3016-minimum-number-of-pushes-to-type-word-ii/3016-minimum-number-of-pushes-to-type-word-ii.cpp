class Solution {
public:
    int minimumPushes(string word) {
        int charCount[26] = {0};
        vector<int> charOccurances;
        for (auto c : word) charCount[c-'a']++;
        for(int i = 0 ; i < 26 ; i ++)  
            if (charCount[i])   charOccurances.push_back(charCount[i]);
            
        sort(charOccurances.begin(),charOccurances.end(),greater<int>());
        
        int keyCount = 0;
        int totalKeyPress = 0;

        for (auto count : charOccurances){
            
            totalKeyPress += count * ((++keyCount-1)/8 + 1);
            /*
                Keycount is b/w [1-8] => key needs to be pressed 1 time
                Keycount is b/w [2-16] => key needs to be pressed 2 time
                ...
            */

        }
        return totalKeyPress;
    }
};