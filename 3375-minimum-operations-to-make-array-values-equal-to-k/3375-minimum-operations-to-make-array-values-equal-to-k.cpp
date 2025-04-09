#define MAX 100
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        bool arr[MAX+1];
        int distinct=0;
        for(auto &n : nums){
            if(n < k)   return -1;
            if((n > k) && (! arr[n])){
                arr[n] = true;
                distinct++;
            }
        }
        return distinct;
    }
};