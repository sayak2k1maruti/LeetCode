class Solution {
public:
    pair<int,int> getDirection(int n){
        return make_pair(n%2 ? 2-n : 0,n%2 ? 0 : 1-n);
        //int directions[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> arr;
        int m = matrix.size(), n = matrix[0].size();
        int directions[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int i = 0,j = 0,di = 0;
        int L = 0,R = n-1,U=0,D=m-1;

        pair <int,int> cycle_detect = make_pair(0,0);

        for (int count = 0 ; count < m*n; count++){
            pair <int,int> direction = getDirection(di);
            if (i < U || j < L || i > D || j > R){
                i -= direction.first;
                j -= direction.second;
                di = (di+1)%4;
                direction = getDirection(di);
                count --;
            }else{
                arr.push_back(matrix[i][j]);
            }
            
            i += direction.first;
            j += direction.second;

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