class Solution {
public:
    bool isPossible(vector<int> &candies, int n,long long children){
        for(auto &i : candies){
            children -= i/n;
            if(children <= 0)   return true;
        }
        return false;
    }
    unsigned long long sum(vector<int> &candies){
        unsigned long long ans=0;
        for(auto &n : candies){
            ans+=n;
        }
        return ans;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        unsigned long long totalC = sum(candies);
        if(totalC < k)  return 0;
        // for(int n=totalC/k;n>0;n--){
        //     if(isPossible(candies,n,k)) return n;
        // }
        //converting above search to binary search
        int left = 1,right=totalC/k;
        int result = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(candies, mid, k)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};