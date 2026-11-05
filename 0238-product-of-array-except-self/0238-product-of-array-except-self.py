class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        ans = [1]*len(nums)
        mul = 1
        for i in range(1,len(nums)+1):
            mul = mul*nums[-i]
            ans[-i] = mul
        mul = 1
        for i in range(len(nums)-1):
            ans[i] = mul * ans[i+1]
            mul *= nums[i]
        ans[-1] = mul
        return ans
        


