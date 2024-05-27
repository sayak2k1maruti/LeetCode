class Solution {
public:
    int specialArray(vector<int>& nums) {
        int arr[1001] = {0};
        for (auto i : nums){
            for(int j = 0; j <=i ; j++) arr[j] ++;
        }
        for(int i = 0 ; i < 1001; i++){
            if (i == arr[i])
                return i;
        }
        return -1;
    }
};