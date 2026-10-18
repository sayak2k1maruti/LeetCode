import math
MOD = 10**9 + 7
def ways(nums):
    if len(nums) < 3:
        return 1
    root = nums[0]
    left,right  = [],[]
    for i in nums[1:]:
        if i < root:
            left.append(i)
        else:
            right.append(i)
    
    return math.comb(len(nums) - 1,max(len(left),len(right))) * ways(left) * ways(right) % MOD

class Solution:
    def numOfWays(self, nums: list[int]) -> int:
        return ways(nums) - 1