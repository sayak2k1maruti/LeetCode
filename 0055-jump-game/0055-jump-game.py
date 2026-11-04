class Solution:
    def canJump(self, nums: list[int]) -> bool:
        farthest = 0
        n = len(nums)
        for i in range(n):
            farthest = max(farthest, i + nums[i])
            if farthest >= n-1:
                return True
            if farthest == i:
                return False

            

        