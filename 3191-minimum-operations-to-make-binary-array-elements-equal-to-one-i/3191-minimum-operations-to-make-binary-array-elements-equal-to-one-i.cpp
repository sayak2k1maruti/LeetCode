class Solution {
public:
    void invrt(int &i){
        i = (!i);return;
    }
    int minOperations(vector<int>& nums) {
        int count = 0;
        for (int i = 0 ; i < nums.size() ; i++ ){
            if (nums[i]) continue;
            if(i+2 >= nums.size())  return -1;
            for(int z = 1 ; z < 3; z++) invrt(nums[i+z]);
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
