class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        s = set(nums)
        ans = 0
        for n in s:
            if n-1 in s:
                continue
            nextn = n+1
            while nextn in s:
                nextn +=1 
            ans = max(ans,nextn-n)
        return ans
            

        