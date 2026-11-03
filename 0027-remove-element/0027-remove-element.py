class Solution:
    def removeElement(self, nums: list[int], val: int) -> int:
        def swap(i,j):
            nums[i] = nums[j]
            nums[j] = val 
        front,end = 0,len(nums) - 1
        while front < end:
            if nums[front]  == val:
                swap(front,end)
                end -= 1
            else:
                front += 1
        if end>= 0 and end < len(nums) and nums[end] == val:
            end -= 1
        return end + 1