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
        float pivot = sqrt(n*(n+1)/2);
        if(pivot==(int)pivot)
            return pivot;
        return -1;
    }
};