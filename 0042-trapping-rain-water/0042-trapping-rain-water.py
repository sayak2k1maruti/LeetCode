class Solution:
    # def trap(self, height: list[int]) -> int:
    #     n = len(height)
    #     maxH = height[-1]
    #     rtl = [0]*n
    #     for i in range(n-1,-1,-1):
    #         maxH = max(maxH,height[i])
    #         rtl[i] = maxH

    #     maxH = 0
    #     water = 0

    #     for i in range(n):
    #         h = height[i]
    #         water += max(min(maxH,rtl[i]) - h,0)
    #         maxH = max(h,maxH)

    #     return water
    def trap(self, height: list[int]) -> int:
        leftM,rightM,water = 0,0,0
        left, right = 0,len(height)-1
        while left<right:
            if height[left] < height[right]:
                leftM = max(leftM,height[left])
                water+= leftM - height[left]
                left += 1
            else:
                rightM = max(rightM,height[right])
                water += rightM - height[right]
                right -= 1
        return water

            