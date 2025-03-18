class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
       int left = 0,right = 0,maxSize=0;
       int orr = 0;
       while(right < nums.size()){
            if(!(orr & nums[right])){
                orr |= nums[right];
                maxSize=max(maxSize,right-left+1);
                right++;
            }else{
                orr ^= nums[left++];
            }
       }
       return maxSize;
    }
};
/*
        a,b,c
        a.b = 0
        b.c = 0
        a.c = 0

        <--d
        a.d = 0, b.d = 0 , c.d = 0
        ==> (a + b + c).d = 0 <- this is our check, [+ is bit wise orr here]

        (a | b | c) ^ a = (a ^ a) | b | c = 0 | b | c = b | c
    */
    