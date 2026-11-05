class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        n = len(nums)
        ans = [1]*n
        mul = 1
        for i in range(1,n+1):
            mul = mul*nums[-i]
            ans[-i] = mul
        mul = 1
        for i in range(n-1):
            ans[i] = mul * ans[i+1]
            mul *= nums[i]
        ans[-1] = mul
        return ans
        


