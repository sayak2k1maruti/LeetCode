class Solution:
    def maxSelectedElements(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        visited = set()
        dp = {}
        def do(i,target):
            if (i,target) in dp:
                return dp[(i,target)]
            if target is None:
                dp[(i,target)] = 1 + max(do(i+1,nums[i]+1), do(i+1,nums[i]+2)); return dp[(i,target)]
            if i>=n:
                return 0
            if nums[i] == target or nums[i]==target-1:
                dp[(i,target)] =  1 + do(i+1,target+1); return dp[(i,target)]
            if nums[i] < target:
                dp[(i,target)] = do(i+1, target); return dp[(i,target)]
            dp[(i,target)] = 0; return dp[(i,target)]
        
        ans = -float('inf')
        for i in range(len(nums)):
            ans = max(ans,do(i,None))
        
        return ans