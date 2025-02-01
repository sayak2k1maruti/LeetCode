class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        bool isOdd = nums[0] & 1;
        for(int i = 1;i < n; i++){
            if ((nums[i] & 1) == isOdd) return false;
            isOdd = nums[i] & 1;
        }
        return true;
    }
};