class Solution:
    def sortPermutation(self, nums: List[int]) -> int:
        ans = 2**64 - 1
        is_sorted = True
        for i in range(len(nums)):
            if nums[i] != i:
                is_sorted = False
                ans &= nums[i]
        return ans if not is_sorted else 0


        