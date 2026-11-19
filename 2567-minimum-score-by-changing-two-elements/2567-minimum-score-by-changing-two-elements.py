import heapq
class Solution:
    def minimizeSum(self, nums: List[int]) -> int:
        if len(nums) <=3 :
            return 0
        min_three = heapq.nsmallest(3, nums)
        max_three = heapq.nlargest(3,nums)
        return min(
            max_three[0] - min_three[-1],
            max_three[-1] - min_three[0],
            max_three[1] - min_three[1]
            )
        