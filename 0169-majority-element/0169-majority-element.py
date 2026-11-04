from collections import Counter
class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        majority =nums[0]
        vote = 0
        for n in nums:
            if vote == 0:
                majority = n
            if n==majority:
                vote += 1
            else:
                vote -= 1
        return majority 
        