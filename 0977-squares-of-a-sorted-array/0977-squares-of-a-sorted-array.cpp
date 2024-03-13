#define MAX 10001
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int hash[MAX] = {0};
        for (int i = 0;i<nums.size(); i++)
            hash[abs(nums[i])] ++;
        int index=0;
        for(int i = 0; i<MAX;i++){
            for(int j=0;j<hash[i]; j++){
                nums[index++] = i*i;
            }
        }
        return nums;
    }
};