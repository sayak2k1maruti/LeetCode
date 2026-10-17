class Solution:

    def singleNumber(self, nums: list[int]) -> int:
        num = 0
        for n in nums:
            num = num ^ n
        return num