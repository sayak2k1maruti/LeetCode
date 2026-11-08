class Solution:
    def minSubArrayLen(self, target: int, nums: list[int]) -> int:
        n = len(nums)
        i,j = 0,0
        ans = n+1
        csum = 0
        for j in range(len(nums)):
            csum += nums[j]
            looped = False
            while csum>=target:
                # ans = min(ans,j-i+1)
                looped = True
                csum -= nums[i]
                i+=1
            if looped:
                ans = min(ans,j-i+2)
                
            
        return ans if ans <= n else 0


