class Solution:
    def summaryRanges(self, nums: list[int]) -> list[str]:
        prev = 0
        ans = []
        if not nums:
            return []
        def append(i,j):
            ans.append(
                f"{nums[i]}" if i==j else f"{nums[i]}->{nums[j]}"
            )
        for i in range(1,len(nums)):
            if nums[i] != nums[i-1] + 1:
                append(prev,i-1)
                prev = i
        append(prev,len(nums)-1)
        
        return ans