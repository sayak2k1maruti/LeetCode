class Solution:
    def minSubArrayLen(self, target: int, nums: list[int]) -> int:
        n = len(nums)
        i,j = 0,0
        ans = n+1
        csum = 0
        while j<len(nums):
            if i>j:
                j = i
                csum = 0
                continue
            csum += nums[j]
            if csum < target:
                j+=1
                continue
            ans = min(ans,j-i+1)
            csum -= nums[i]
            csum -= nums[j]
            i+=1
            
        return ans if ans <= n else 0


