class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        indx_map = {nums[i] : i for i in range(len(nums))}
        # a + b = target
        for i in range(len(nums)-1):
            a = nums[i]
            b = target - a
            if b in indx_map and indx_map[b] != i:
                return [i,indx_map[b]]
        return [-1,-1]
