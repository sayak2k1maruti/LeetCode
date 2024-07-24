


class Solution {
public:
    static bool comparefn(pair<int,int> a, pair<int,int> b){
        return a.first < b.first;
    }
    int decode(int n,vector <int> &mapping){
        if(! n) return mapping[0];
        int num = 0;
        for (int i = 1;n;n/=10,i*=10)
            num = i*mapping[n%10] + num;
        
        return num;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        pair <int,int> num_map[nums.size()];
        
        for (int i= 0 ; i < nums.size(); i++ )
            num_map[i] = make_pair(decode(nums[i],mapping),nums[i]);

        sort(num_map,num_map + nums.size(),comparefn);
        
        for (int i = 0 ; i < nums.size(); i++)  
            nums[i] = num_map[i].second;
        
        return nums;
    }
};