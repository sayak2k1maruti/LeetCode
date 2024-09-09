class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> arr;
        int m = matrix.size(), n = matrix[0].size();
        int directions[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int i = 0,j = 0,di = 0;
        int L = 0,R = n-1,U=0,D=m-1;

        pair <int,int> cycle_detect = make_pair(0,0);

        for (int count = 0 ; count < m*n; count++){
            if (i < U || j < L || i > D || j > R){
                di = (di+1)%4;
                i += directions[di][0];
                j += directions[di][1];
                continue;
                count --;
            }
            arr.push_back(matrix[i][j]);
            int _i = i + directions[di][0];
            int _j = j + directions[di][1];
            if (_i < U || _j < L || _i > D || _j > R){
                di = (di+1)%4;
            }
            i += directions[di][0];
            j += directions[di][1];
            if (i==cycle_detect.first && j == cycle_detect.second){
                i++; j++;L++;R--;U++;D--;
                cycle_detect.first = i;
                cycle_detect.second = j;
                di = 0;
            }

        }
        return arr;
    }
};