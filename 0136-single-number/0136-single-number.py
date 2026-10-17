from collections import defaultdict
class Solution:

    def singleNumber(self, nums: list[int]) -> int:
        # num = 0
        # for n in nums:
        #     num = num ^ n
        # return num
        check =  defaultdict(bool)
        for n in nums:
            check[n] = not check[n]
        for i,j in check.items():
            if j:
                return i