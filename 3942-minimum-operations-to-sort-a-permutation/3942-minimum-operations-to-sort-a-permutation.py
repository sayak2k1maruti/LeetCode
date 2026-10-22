class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums) 
        if n == 1:
            return 0
        z = nums.index(0)
        m = nums.index(n-1)
        a = all(nums[(z+i)%n] < nums[(z+1+i)%n] for i in range(0,n-1))
        b = all(nums[(m+i)%n] > nums[(m+1+i)%n] for i in range(0,n-1))
        if not (a or b):
            return -1
        if a:
            return min(z,n-z+2)
        elif b:
            return min(m+1,n-m+1)