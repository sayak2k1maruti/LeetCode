#define MAX 100
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto &n : nums) mp[n]++;
        if(mp.size() == 1){
            if(nums[0] < k) return -1;
            return nums[0] == k ? 0 : 1;
        }
        int minOperation = 0;
        for(auto &[n,count] : mp){
            if(n < k)   return -1;
            if(n > k) minOperation ++;
        }
        return minOperation ? minOperation : -1;
    }
};