class Solution {
public:
    void invrt(int &i){
        i ^= 1; return;
    }
    int minOperations(vector<int>& nums) {
        int count = 0,n = nums.size();
        for (int i = 0 ; i < n ; i++ ){
            if (nums[i]) continue;
            if(i+2 >= n)  return -1;
            for(int z = 1 ; z < 3; z++) nums[i+z] ^= 1;
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
