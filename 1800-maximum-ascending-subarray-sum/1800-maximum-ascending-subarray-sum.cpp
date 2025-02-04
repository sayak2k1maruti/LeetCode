class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size(),ans=0,sum=nums[0];
        for(int l=0,r=1;r<n;sum+=nums[r++]){
            if(nums[r] <= nums[r-1]){
                ans = max(ans,sum);
                l = r;
                sum = 0;
            }
            //cout << " " << nums[l] <<" " << nums[r] << " " << sum <<endl;
        }
        return max(ans,sum);
    }
};