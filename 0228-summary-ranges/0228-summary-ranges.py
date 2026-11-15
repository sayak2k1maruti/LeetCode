class Solution:
    def summaryRanges(self, nums: list[int]) -> list[str]:
        prev = 0
        ans = []
        if not nums:
            return []
        for i in range(1,len(nums)):
            if nums[i] != nums[i-1] + 1:
                if prev == i-1:
                    ans.append(f"{nums[prev]}")
                else:
                    ans.append(f"{nums[prev]}->{nums[i-1]}")
                prev = i
        if prev == len(nums)-1:
            ans.append(f"{nums[prev]}")
        else:
            ans.append(f"{nums[prev]}->{nums[len(nums)-1]}")
        
        return ans