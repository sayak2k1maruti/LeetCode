class Solution {
public:
    int sumOfDigit(int n){
        int sum = 0;
        while(n){
            sum += n%10;
            n/=10;
        }
        return sum;
    }
    int findMaxSum(vector <int> &nums){
        int n = nums.size();
        int sum = -1;
        if(n<2) return -1;
        for(int i = 0; i < n-1; i ++){
            for (int j = i+1 ; j < n ; j ++){
                sum = max(sum,nums[i] + nums[j]);
            }
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map <int,vector<int>> sumOfDigitMap;
        int sum = -1;
        for(auto n : nums)  sumOfDigitMap[sumOfDigit(n)].push_back(n);
        for(auto &[key,arr] : sumOfDigitMap){
            sum = max(sum,findMaxSum(arr));
        }
        return sum;
    }
};