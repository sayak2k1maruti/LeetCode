class Solution {
public:
    bool canPartition(vector<int>& nums) {
        set<int> allSums;
        int tsum = 0;
        for(auto &i : nums) tsum += i;
        int halfSum = tsum/2;
        if(tsum & 1) return false;
        allSums.insert(0);
        for(auto &i : nums){
            set <int> tempAllSums;
            for(auto &n : allSums){
                tempAllSums.insert(n);
                tempAllSums.insert(n + i);
            }
            allSums = tempAllSums;
            if(allSums.find(halfSum) != allSums.end())  return true;
        }
        return allSums.find(halfSum) != allSums.end();
    }
};