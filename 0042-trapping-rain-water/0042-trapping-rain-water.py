class Solution:
    def trap(self, height: list[int]) -> int:
        n = len(height)
        maxH = height[-1]
        rtl = [0]*n
        for i in range(n-1,-1,-1):
            maxH = max(maxH,height[i])
            rtl[i] = maxH

        maxH = 0
        water = 0

        for i in range(n):
            h = height[i]
            water += max(min(maxH,rtl[i]) - h,0)
            maxH = max(h,maxH)

        return water
            