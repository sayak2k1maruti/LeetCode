class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tsum = 0,hsum;
        for(auto &i : nums) tsum += i;
        if(tsum & 1)    return false;
        hsum = tsum/2;
        bool totalSums[100*200 + 1] = {false};
        totalSums[0] = true;
        for(auto &n : nums){
            for(int i = hsum ; i >= n ; i--){
                if(totalSums[i-n]){
                    totalSums[i] = true;
                }
                if(totalSums[hsum])  return true;
            }
        }
        return totalSums[hsum];
    }
};