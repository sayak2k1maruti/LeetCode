#define MAX 100
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        bool usedNums[MAX+1] = {false};
        int n = nums.size();
        int i = n-1;
        for(; i >= 0 ; i--){
            if(usedNums[nums[i]])   break;
            usedNums[nums[i]] = true;
        }
        return ceil((float)(i+1)/3);
    }
};