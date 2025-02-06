class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size(),count = 0;
        unordered_map<int,int> productMap;
        for(int i = 0 ; i < n; i++){
            for(int j= i+1; j < n ; j++)
                productMap[nums[i]*nums[j]] ++;
        }
        for(auto& [product ,n] : productMap){
            if(n > 1){
                count += 8 * n * (n-1)/2;
            }
        }
        return count;
    }
};