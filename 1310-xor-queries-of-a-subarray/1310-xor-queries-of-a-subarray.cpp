class Solution {
public:
    int xor_arr(int start,int end,vector <int>& arr){
        int xor_value = arr[start];
        for (int i = start+1;i <= end; i++){
            xor_value ^= arr[i];
        }
        return xor_value;
    }
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result_arr(queries.size(),0);
        for(int i = 0 ; i < queries.size();i++){
            result_arr[i] = xor_arr(queries[i][0],queries[i][1],arr);
        }
        return result_arr;
    }
};