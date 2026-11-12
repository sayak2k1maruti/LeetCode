class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        dec = inc = 0
        startdec = startinc = 0
        for end in range(1,len(nums)):
            if nums[end] <= nums[end-1]:
                inc = max(inc,end-startinc)
                startinc = end
            if nums[end] >= nums[end-1]:
                dec = max(dec,end-startdec)
                startdec = end
        return max(dec,inc,len(nums)-startinc,len(nums)-startdec)