class Solution:
    def minimumSumSubarray(self, nums: List[int], l: int, r: int) -> int: 
        anss = float('inf')
        for x in range(l,r+1):
            ans = 0
            for iii in range(x):
                ans += nums[iii]
            if ans>0:
                anss = min(ans,anss)
            for i in range(0,len(nums)-x):
                ans -= nums[i]
                ans += nums[i+x]
                if ans>0:
                    anss = min(ans,anss)
        return anss if anss != float('inf') else -1
        