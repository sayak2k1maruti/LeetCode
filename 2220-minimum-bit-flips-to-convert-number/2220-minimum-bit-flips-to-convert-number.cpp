#define BIT_LEN 32
class Solution {
public:

    int countNumOfOneBit(int n){
        int count = 0;
        for(;n;n=n>>1)  count += n%2;
        return count;
    }
    int minBitFlips(int start, int goal) {       
        return countNumOfOneBit(start ^ goal);
    }
};