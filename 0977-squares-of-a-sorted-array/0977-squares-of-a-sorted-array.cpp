#define MAX 10001
class Solution {

public:
    vector<int> merge(vector<int>& nums, int partition){
        vector<int> arr(nums.size());
        int left_index = partition, right_index = partition+1,index=0;
        while (left_index >= 0 && right_index < nums.size()){
            if(nums[left_index] < nums[right_index]){
                arr[index++] = nums[left_index]*nums[left_index];
                left_index--;
            }else{
                arr[index++] = nums[right_index]*nums[right_index];
                right_index++;             
            }
        }
        while(left_index >= 0){
            arr[index++] = nums[left_index] * nums[left_index];
            left_index--;
        }
        while(right_index < nums.size()){
            arr[index++] = nums[right_index]*nums[right_index];
            right_index++;
        }
        return arr;
    }
    vector<int> sortedSquares(vector<int>& nums) {
        int partition = 0;
        for(;partition<nums.size() && nums[partition] < 0;partition++){
            nums[partition] = abs(nums[partition]);
        }
        return merge(nums,partition-1);
    }
};