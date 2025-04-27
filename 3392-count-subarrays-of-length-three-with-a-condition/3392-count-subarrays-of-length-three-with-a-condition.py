class Solution(object):
    def countSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return len([True for i in range(0,len(nums)-2) if 2* (nums[i] + nums[i+2]) == nums[i+1]])
        