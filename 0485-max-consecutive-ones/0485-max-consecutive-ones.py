class Solution:
    def findMaxConsecutiveOnes(self, nums: list[int]) -> int:
        count = 0;maxCount=0
        for n in nums:
            if n == 0:
                maxCount = max(maxCount,count)
                count = 0
                continue
            count += 1
        return max(maxCount,count)
