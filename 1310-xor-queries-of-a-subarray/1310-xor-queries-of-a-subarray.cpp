class Solution {
public:
    int xor_arr(int start,int end,vector <int>& arr){
        if(start == end)    return arr[start];
        return arr[start] ^ xor_arr(start+1,end,arr);
    }
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result_arr(queries.size(),0);
        for(int i = 0 ; i < queries.size();i++){
            result_arr[i] = xor_arr(queries[i][0],queries[i][1],arr);
        }
        return result_arr;
    }
};