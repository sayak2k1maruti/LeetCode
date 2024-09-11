#define BIT_LEN 32
class Solution {
public:
    void updateBitArr(int n,int* arr){
        for(int i=0;n;n=n>>1,i++)
            arr[i] ^=  n%2;
    }
    int minBitFlips(int start, int goal) {
        int arr[BIT_LEN] = {0};
        updateBitArr(start,arr);
        updateBitArr(goal,arr);
        return count(arr,arr+BIT_LEN,1);
    }
};