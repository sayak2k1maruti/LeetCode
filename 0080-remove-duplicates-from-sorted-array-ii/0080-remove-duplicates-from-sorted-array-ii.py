class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        index = 1
        count = 1
        for i in range(1,len(nums)):
            if nums[i] == nums[index - 1]:
                count += 1
            if count <= 2 or nums[i] != nums[index - 1]:
                if nums[i] != nums[index - 1]:
                    count = 1
                nums[index] = nums[i]
                index += 1
        return index
        