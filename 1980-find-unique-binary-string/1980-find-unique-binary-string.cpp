class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";
        int i = 0;
        for(auto n : nums)  ans.push_back(n[i++] == '0' ? '1' : '0');
        return ans;
    }
};