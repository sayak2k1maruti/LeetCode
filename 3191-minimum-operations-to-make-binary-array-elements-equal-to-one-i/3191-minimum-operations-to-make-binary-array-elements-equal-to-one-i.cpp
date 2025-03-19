class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0,n = nums.size();
        for (int i = 0 ; i < n ; i++ ){
            if (nums[i]) continue;
            if(i+2 >= n)  return -1;
            nums[i+1] ^= 1;
            nums[i+2] ^= 1;
            count++;
        }
        return count;
    }
};

/*
0 1 1 1 0 0
1 0 0 1 0 0
1 1 1 0 0 0
1 1 1 1 1 1

0 1 1 1
1 0 0 1
1 1 1 0
*/
