class Solution {
public:

    vector<int> sortArray(vector<int>& nums) {
        int arr[50000*2+1] = {0};
        for (auto n : nums)
            arr[n + 50000] ++;
        int indx = 0;
        for(int i = 0; i < 50000*2+1; i++)
            for (int j = 0 ; j < arr[i] ; j++)
                nums[indx++] = i - 50000;
        return nums;
    }
};