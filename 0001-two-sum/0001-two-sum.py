class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        indx_map = {}
        # a + b = target
        for i in range(len(nums)):
            a = nums[i]
            b = target - a
            if b in indx_map:
                return [i,indx_map[b]]
            indx_map[a] = i
        return [-1,-1]
