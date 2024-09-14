class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result_arr(queries.size(),0);
        for(int i = 1; i < arr.size();i++){
            arr[i] ^= arr[i-1];
        }
        int indx=0;
        for(auto query: queries){
            if (query[0] == 0)
                result_arr[indx++] = arr[query[1]];
            else    result_arr[indx++] = arr[query[1]] ^ arr[query[0]-1];
        }
        return result_arr;
    }
};