class Solution {
public:
    int longestSubarray(int n,vector<int> &nums,bool indicator){
        int ans = 1;
        int l=0,r=1;
        for(;r<n;r++){
            if(!(indicator ^ (nums[r]>nums[r-1]))  || (nums[r] == nums[r-1])){
                ans = max(ans,r-l);
                l = r;
            }
        }
        return max(ans,r-l);
    }
    int longestMonotonicSubarray(vector<int>& nums) {
        return max(longestSubarray(nums.size(),nums,true) ,longestSubarray(nums.size(),nums,false) );
    }
};