class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count = 0, smaller = 0;
        vector <int> ans;
        for (auto n : nums){
            if(n<target) smaller++;
            else if(n==target) count++;
        }
        if(count){
            for(int i = 0;i < count;ans.push_back(smaller + i++));
        }
        return ans;
    }
};