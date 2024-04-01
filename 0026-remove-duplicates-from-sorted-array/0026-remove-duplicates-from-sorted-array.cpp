class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1,index=0;
        for(int i = 1 ; i< nums.size();i++){
            if(nums[i] != nums[index]){
                swap(nums[i],nums[++index]);
                count++;
            }
        }
        return count;
    }
};