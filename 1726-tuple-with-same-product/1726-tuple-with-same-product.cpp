class Solution {
public:
    int binarySearch(int n,int l,int r,vector<int> & nums){
        int mid;
        while(l<=r){
            mid = l + (r-l)/2;
            if(nums[mid]==n)    return mid;
            if(nums[mid] > n)   r = mid-1;
            else l = mid+1;
        }
        return -1;
    }
    int tupleSameProduct(vector<int>& nums) {
        int count = 0;
        map<int,int> productMap;
        for(int i = 0 ; i < nums.size(); i++){
            for(int j= i+1; j < nums.size() ; j++)
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