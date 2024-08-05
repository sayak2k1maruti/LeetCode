class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int> strMap;
        vector<string> distinctArr;
        for (auto str : arr) strMap[str] ++;
        for (auto str : arr) 
            if (strMap[str] == 1)
                distinctArr.push_back(str);
        return distinctArr.size() >= k ? distinctArr[k-1] : "";
    }
};