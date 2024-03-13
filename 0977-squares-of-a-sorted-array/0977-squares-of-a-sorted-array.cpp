class Solution {
public:
    int partition(vector<int>&nums, int left,int right){
        int pivot = nums[right];
        int partition = left;
        while(left < right){
            if(nums[left] < pivot){
                swap(nums[left],nums[partition]);
                partition ++;
            }
            left++;
        }
        swap(nums[partition],nums[right]);
        return partition;
    }
    void quick_sort(vector<int>&nums,int left, int right){
        if (left<right){
            int p = partition(nums,left,right);
            quick_sort(nums,left,p-1);
            quick_sort(nums,p+1,right);
        }
        return;
    }
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i = 0; i< nums.size(); i++)
            nums[i] = nums[i] * nums[i];
        quick_sort(nums,0,nums.size()-1);
        return nums;
    }
};