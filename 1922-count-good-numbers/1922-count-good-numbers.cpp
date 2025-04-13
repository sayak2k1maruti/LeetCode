#define P 1000000007
#define ull unsigned long long
class Solution {
public:
    ull powFast(ull n , ull k){
        if(k ==0)   return 1;
        ull ans = powFast(n,k/2);
        if(k & 1)   return ans * ans * n % P;
        else return ans * ans % P;
    }
    int countGoodNumbers(long long n) {
        ull primePermutations =  powFast(4,n/2);//pow(4,n/2)
        ull evenPermutations = powFast(     5,  (n/2+(n&1))   );
        return primePermutations * evenPermutations % P;
    }
};