class Solution {
public:
    bool isSortedRotated(int min,vector<int>&nums,int n){
        int prev = nums[min];
        for(int indx=min+1,count=1;count <n; count++,indx++){
            if(indx>=n) indx=0;
            cout << prev<< " "<<nums[indx] << endl;
            if(nums[indx] < prev)   return false;
            prev = nums[indx];
        }
        return true;
    }
    bool check(vector<int>& nums) {
        for(int i = 0 ; i < nums.size();i++)
            if( isSortedRotated(i,nums,nums.size()) )     return true;
        return false;
    }
};