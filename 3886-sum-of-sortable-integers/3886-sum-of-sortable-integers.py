from collections import Counter
class Solution:
    def sortableIntegers(self, nums: list[int]) -> int:
        def check_cyclic_sorted(arr):
            dir_change = 0
            for i in range(len(arr)):
                if arr[i] > arr[(i+1) % len(arr)]:
                    dir_change +=1
            return dir_change <= 1
        def check(nums,sorted_nums,k):
            for i in range(0,len(nums),k):
                if Counter(nums[i:i+k]) != Counter(sorted_nums[i:i+k]):   
                    return False
                elif not check_cyclic_sorted(nums[i:i+k]):
                    return False
            return True

        sorted_nums = sorted(nums)
        ans = 0

        for i in range(1,len(nums)+1):
            if len(nums)%i == 0 and check(nums,sorted_nums,i):
                ans += i
        return ans

