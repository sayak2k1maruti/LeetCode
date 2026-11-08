from itertools import accumulate
class Solution:
    def minSubArrayLen(self, target: int, nums: list[int]) -> int:
        sumNums = list(accumulate(nums))
        n = len(nums)
        i,j = 0,0
        ans = n+1
        csum = nums[0]
        while j<len(nums):
            if i>j:
                j=i
                if j <len(nums):
                    csum = nums[j]
                continue
            # csum = sumNums[j] - sumNums[i-1] if i>0 else sumNums[j]
            
            if csum >= target:
                ans = min(ans,j-i + 1)
                csum -= nums[i]
                i+=1
            else:
                j += 1
                if j < len(nums):
                    csum += nums[j]
        return ans if ans <= n else 0


