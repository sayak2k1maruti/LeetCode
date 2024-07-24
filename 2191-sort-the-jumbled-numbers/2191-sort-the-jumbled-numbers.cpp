


class Solution {
public:
    static bool comparefn(pair<int,int> a, pair<int,int> b){
        return a.first < b.first;
    }
    int decode(int n,vector <int> &mapping){
        if(! n) return mapping[0];
        int num = 0;
        for (int i = 1;n;n/=10,i*=10){
            num = i*mapping[n%10] + num;
        }
        return num;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector <pair<int,int>> num_map;
        for (auto it = nums.begin(); it != nums.end(); it ++){
            
            int decoded_num = decode(*it,mapping);
            num_map.push_back(make_pair(decoded_num,*it));
        }
        sort(num_map.begin(),num_map.end(),comparefn);
        int indx = 0;
        for (auto it : num_map) nums[indx++] = it.second;
        return nums;
    }
};