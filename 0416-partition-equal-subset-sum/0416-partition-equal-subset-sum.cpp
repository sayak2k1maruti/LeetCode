class Solution {
public:
    bool findSum(vector<int>& nums,int i,int sum,int** cache){
        
        if(sum < 0) return false;
        if(i >= nums.size())    return false;

        if(cache[i][sum] != -1)   return cache[i][sum];
        if(sum==0)  return cache[i][0] = true;

        return cache[i][sum] = findSum(nums,i+1,sum-nums[i],cache) || findSum(nums,i+1,sum,cache); 
    }
    bool canPartition(vector<int>& nums) {
       int sum = 0;
       for(auto &i : nums)  sum += i;
       if(sum & 1) return false;
       int **cache;
       cache = new int *[nums.size()+1];
       for(int i = 0 ; i <= nums.size(); i++){
           cache[i] = new int[sum/2 + 1];
           for(int j = 0 ; j <= sum/2 ; j ++){
                cache[i][j] = -1;
           }
       }
       for(int i = 0 ; i <= nums.size(); i++)
            for(int j = 0 ; j <= sum/2 ; j++)   
                cache[i][j] = -1;

       return findSum(nums,0,sum/2,cache);
    }
};