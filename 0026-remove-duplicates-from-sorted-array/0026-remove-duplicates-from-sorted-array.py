class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        index = 1
        if len(nums) <= 1:
            return 1
        for current in range(1,len(nums)):
            if nums[current] != nums[index-1]:
                nums[index] = nums[current]
                index += 1
        return index




        