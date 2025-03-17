#define MAX_NUM 500
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int arr[MAX_NUM+1] = {0};
        for(auto &n : nums)
            arr[n]++;

        for(int i = 0 ; i <= MAX_NUM ; i++)
            if(arr[i] & 1)  
                return false;
        return true;
    }
};