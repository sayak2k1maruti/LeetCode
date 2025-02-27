class Solution {
public:
    unordered_map<int,int> indxMap(vector <int>& arr){
        unordered_map<int,int> mp;
        for(int i = 0 ; i < arr.size(); i++)    mp[arr[i]] = i;
        return mp;
    }
    int flength(unordered_set <int> & st,int a, int b){
        if(st.count(a+b)){
            return 1 + flength(st,b,a+b);
        }
        return 0;
    }
    int lenLongestFibSubseq(vector<int>& arr) { 
        int maxLen = 0;
        unordered_set<int> st(arr.begin(),arr.end());
        for(int l = 0 ; l <arr.size()-1; l++){
            for(int r = l+1; r < arr.size(); r++){
                maxLen = max(maxLen,flength(st,arr[l],arr[r]));
            }
        }
        return maxLen ? maxLen + 2 : 0;
    }
};