#define BIT_LEN 32
class Solution {
public:
    void updateBitArr(int n,int* arr){
        for(int i=0;n;n=n/2,i++)
            arr[i] ^=  n%2;
    }
    int count(int* arr){
        int count = 0;
        for(int i = 0 ; i < BIT_LEN; i++)   count += arr[i];
        return count;
    }
    int minBitFlips(int start, int goal) {
        int arr[BIT_LEN] = {0};
        updateBitArr(start,arr);
        updateBitArr(goal,arr);
        return count(arr);
    }
};