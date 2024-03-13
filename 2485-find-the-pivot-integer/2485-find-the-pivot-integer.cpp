class Solution {
public:
    int pivotInteger(int n) {
        int pivot = 1;
        int left_sum = 0;
        int right_sum = n*(n+1)/2;
        while(pivot <= n){
            left_sum+= pivot;
            right_sum -= pivot;
            if(left_sum == right_sum + pivot){
                return pivot;
            }
            pivot++;
        }
        return -1;
    }
};