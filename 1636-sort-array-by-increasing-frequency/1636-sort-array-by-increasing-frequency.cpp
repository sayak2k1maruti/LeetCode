class Solution {
public:
    int getIndex(int n) {return n + 100;}
    vector<int> frequencySort(vector<int>& nums) {
        map <int,int> frequency_map;
        //int max_occurs = 0;
        for (auto n : nums) {
            frequency_map[n] ++;
            //max_occurs = max(frequency_map[n],max_occurs);
        }
        set <int> frequency_map_T[200+1];
        //for(int i = 1; i <= max_occurs; i++)    frequency_map_T[i] = new set<int>;
        
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