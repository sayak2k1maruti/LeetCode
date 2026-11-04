from collections import Counter
class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        freq = Counter(nums)
        n = len(nums)
        for num,f in freq.items():
            if f > n/2:
                return num
        
        