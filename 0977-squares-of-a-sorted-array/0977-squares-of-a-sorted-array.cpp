#define MAX 10000
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int hash[MAX] = {0};
        for (int i = 0;i<nums.size(); i++)
            hash[nums[i]*nums[i]] ++;
        int index=0;
        for(int i = 0; i<MAX;i++){
            for(int j=0;j<hash[i]; j++){
                nums[index++] = i;
            }
        }
        return nums;
    }
};