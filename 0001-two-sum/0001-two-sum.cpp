class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> indx_map;
        for(int i=0; i<nums.size(); i++)    indx_map[nums[i]] = i;
        for(int i=0; i<nums.size(); i++){
            int b=target - nums[i];
            auto it = indx_map.find(b);
            if(it == indx_map.end())    continue;
            if(it->second == i) continue;
            return {i,it->second};
        }
        return {-1,-1};
    }
};