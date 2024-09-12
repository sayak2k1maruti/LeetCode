#define N 128
class Solution {
public:
    string frequencySort(string s) {
        int arr[N] = {0};
        vector<pair<int,char>> freqMapArr;
        for (auto c : s)    arr[c]++;
        for(int i = 0 ; i < N;i++) 
            if (arr[i]) freqMapArr.push_back(make_pair(arr[i],(char)(i)));
        sort(freqMapArr.begin(),freqMapArr.end(),greater<>());
        int indx=0;
        for(auto it : freqMapArr){
            for(int i = 0; i < it.first;i++)    s[indx++] = it.second;
        }
        return s;
    }
};