class Solution {
public:
    int sumOfDigit(int n){
        int sum = 0;
        for(;n;n=n/10){
            sum += n%10;
        }
        return sum;
    }
    int sumOffTwoLargestNumber(vector <int> &nums){
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
            if (arr.size() >= 2)    sum = max(sum,sumOffTwoLargestNumber(arr));
        }
        return sum;
    }
};