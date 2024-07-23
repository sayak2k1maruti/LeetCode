class Solution {
public:
    int getIndex(int n) {return n + 100;}
    vector<int> frequencySort(vector<int>& nums) {
        map <int,int> frequency_map;
        for (auto n : nums) {
            frequency_map[n] ++;
        }
        set <int> frequency_map_T[200+1];
        for(auto it : frequency_map){
            frequency_map_T[it.second].insert(it.first);
        }
        int indx = 0;
        for (int i = 1; i < 200 + 1; i++){
            if (! frequency_map_T[i].empty()){
                for(auto it = frequency_map_T[i].rbegin();it != frequency_map_T[i].rend();it++){
                    for(int j = 0; j < i ; j ++)    nums[indx++] = *it;
                } 
            }
        }
        return nums;

    }
};