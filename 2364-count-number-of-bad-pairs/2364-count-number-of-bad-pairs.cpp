class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long int n = nums.size();
        map<int,long long int> nums1; 
        for(int i = 0 ; i < n ; i++){
            nums1[nums[i]-i]++;
        }
        long long int goodPairs = 0;
        for(auto &[diff,count] : nums1){
            goodPairs += count * (count-1)/2;
        }
        long long int totalComb = n*(n-1)/2;
        return totalComb - goodPairs;
    }
};