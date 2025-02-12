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
    int sumOffTwoLargestNumber(vector <int> &nums){
        if(nums.size() < 2) return -1;
        int max = -1,secondMax = -1;
        for(auto &n : nums){
            if(n > max){
                secondMax = max;
                max = n;
            }else if(n > secondMax){
                secondMax = n;
            }
        }
        return max+secondMax;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map <int,vector<int>> sumOfDigitMap;
        int sum = -1;
        for(auto n : nums)  sumOfDigitMap[sumOfDigit(n)].push_back(n);
        for(auto &[key,arr] : sumOfDigitMap){
            sum = max(sum,sumOffTwoLargestNumber(arr));
        }
        return sum;
    }
};