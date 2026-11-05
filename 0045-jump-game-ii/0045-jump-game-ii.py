class Solution:
    def jump(self, nums: list[int]) -> int:
        n = len(nums)
        end = nums[0]
        farest = end
        if n==1:
            return 0
        jump = 1
        for i in range(n-1):
            farest = max(farest,nums[i]+i)
            if i==end:
                jump +=1
                end = farest
                if end >= n-1:
                    break

        return jump




        

        