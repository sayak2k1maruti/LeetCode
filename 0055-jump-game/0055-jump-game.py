class Solution:
    def canJump(self, nums: list[int]) -> bool:
        n = len(nums)
        possible = [None]*n
        def is_possible(start):
            
            if nums[start] + start >= n-1:
                return True
            if possible[start] is not None:
                return possible[start]
            if nums[start] == 0:
                possible[start] =  False
                return False
            for i in reversed(range(start+1,nums[start]+start+1)):
                if is_possible(i):
                    possible[start] =  True
                    return True
            possible[start] = False
            return False
        
        return is_possible(0)
            

        