class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxTriplet = 0;

        vector<long long> right_max(n,0);

        int temp = nums[n-1];
        for(int i = n-1 ; i >= 0 ; i--){
            right_max[i] = temp;
            temp=max(temp,nums[i]);
        }
        int left_max = nums[0];
        for(int j = 1; j < n-1 ; j++){
            maxTriplet = max(maxTriplet,(left_max - nums[j]) * right_max[j]);
            left_max = max(left_max,nums[j]);
        }
        return maxTriplet;
    }
};