class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        prev, current , index = 0,1,1
        if len(nums) <= 1:
            return 1
        while current< len(nums):
            if nums[current] != nums[prev]:
                nums[index] = nums[current]
                prev = index
                index += 1
            current += 1
        return index



        