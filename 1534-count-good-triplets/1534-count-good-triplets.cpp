class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int numCount[1001] = {0};
        int n = arr.size();
        int count = 0;

        for(int j = 0 ; j < n ; j++){
            for(int k = j+1; k < n; k++){
                int xj =arr[j];
                int xk =arr[k];
                if(abs(xj-xk) <= b){
                    int low = max(0,max(xj-a,xk-c));
                    int high = min(min(xj+a,xk+c),1000);
                    if(low <= high){
                        if(low == 0){
                            count += numCount[high];
                        }
                        else count += numCount[high] - numCount[low-1];
                    }
                }
            }
            for(int z = arr[j]; z <= 1000; z++) numCount[z]++;
        }
        return count;
    }
};