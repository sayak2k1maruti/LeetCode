class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        current , index = 1,1
        if len(nums) <= 1:
            return 1
        while current< len(nums):
            if nums[current] != nums[index-1]:
                nums[index] = nums[current]
                index += 1
            current += 1
        return index



        