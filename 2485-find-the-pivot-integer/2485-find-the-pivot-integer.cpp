#include<cmath>
class Solution {
public:
    int pivotInteger(int n) {
        /*
        p*(p+1)/2 = n*(n+1)/2 - (p-1)*p/2
        p^2 + p = n^2 + n - p^2 + p
        2p^2 = n^2 + n
        p^2 = (n^2 + n)/2
        p^2 = n*(n+1)/2
        */
        int S = n*(n+1)/2;
        int pivot = sqrt(S);
        if(pivot*pivot==S)
            return pivot;
        return -1;
    }
};