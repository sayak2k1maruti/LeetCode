class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int> strMap;

        for (auto str : arr) strMap[str] ++;

        int indx = 0;
        for (auto str : arr){
            if (strMap[str] == 1)
                indx++;
            if(indx==k) return str;
        }
        return "";
    }
};