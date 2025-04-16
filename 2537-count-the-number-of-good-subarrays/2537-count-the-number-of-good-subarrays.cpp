class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        map <int,int> freqMap;
        int n = nums.size();
        int left = 0;
        int right = -1;
        long long ans =0;
        int count = 0;
        while(left < n){
            while(count < k && right < n-1){
                ++right;
                count += freqMap[nums[right]];
                freqMap[nums[right]]++;
            } 
            if(count >=k)   ans += n - right;
            freqMap[nums[left]]--;
            count -= freqMap[nums[left]];
            left++;
        }
        return ans;
    }
};