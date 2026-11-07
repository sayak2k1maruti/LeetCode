class Solution:
    def maxArea(self, height: list[int]) -> int:
        i,j = 0,len(height) - 1
        ans = 0
        while i < j:    
            if height[i] > height[j]:
                ans = max(ans,height[j] * (j-i))
                j-=1
            else:
                ans = max(ans,height[i] * (j-i))
                i +=1
        return ans