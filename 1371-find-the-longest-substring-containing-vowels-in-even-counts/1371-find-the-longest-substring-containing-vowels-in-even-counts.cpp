class Solution {
public:

    void tweakChar(char &c){
        c = (c=='1') ? '0' : '1';
    }
    void updateVowelStr(string& vowels,char &c){
        if (c == 'a')   tweakChar(vowels[0]);
        else if (c == 'e')   tweakChar(vowels[1]);
        else if (c == 'i')   tweakChar(vowels[2]);
        else if (c == 'o')   tweakChar(vowels[3]);
        else if (c == 'u')   tweakChar(vowels[4]);
    }
    int findTheLongestSubstring(string s) {
        map <string,int> vowelsMap;
        string vowels = "00000";
        vowelsMap[vowels] = -1;
        int longestStretch  = 0;
        for (int i = 0 ; i < s.size(); i++){
            updateVowelStr(vowels,s[i]);
            if((vowels != "00000") && (vowelsMap.find(vowels) == vowelsMap.end()))   vowelsMap[vowels] = i;
            longestStretch = max(longestStretch,i - vowelsMap[vowels]);
        }
        return longestStretch;
    }
};