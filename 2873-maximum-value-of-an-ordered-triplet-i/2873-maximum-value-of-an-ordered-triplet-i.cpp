class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxTriplet = 0;
        vector<long long> left_max(n);
        vector<long long> right_max(n);
        int temp = nums[0];
        for(int i = 0 ; i < n ; i ++){
            left_max[i] = temp;
            temp = max(temp,nums[i]);
        }
        temp = nums[n-1];
        for(int i = n-1 ; i >= 0 ; i--){
            right_max[i] = temp;
            temp=max(temp,nums[i]);
        }

        for(int j = 1; j < n-1 ; j++){
            //cout << left_max[j] << " " << nums[j] << " " << right_max[j] << endl;
            maxTriplet = max(maxTriplet,(left_max[j] - nums[j]) * right_max[j]);
        }
        return maxTriplet;
    }
};