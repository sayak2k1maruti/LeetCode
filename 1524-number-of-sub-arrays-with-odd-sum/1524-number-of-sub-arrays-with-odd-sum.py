MOD = 10**9 + 7
class Solution:
    def numOfSubarrays(self, arr: list[int]) -> int:
        ans = 0
        even,odd = 0,0
        for n in arr:
            if n & 1:
                even, odd = odd, even + 1 
            else:
                even += 1
            ans += odd
        return ans%MOD


        # for i in range(len(arr)):
        #     odd_count = 0
        #     for j in range(i,len(arr)):
        #         if  arr[j] & 1:
        #             odd_count += 1
        #         ans += odd_count & 1
            
        return ans % MOD
                
