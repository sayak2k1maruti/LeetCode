class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        def twoSum(i,j,target):
            ans = []
            while i < j :
                s = nums[i] + nums[j]
                if s > target:
                    j -= 1
                elif s < target:
                    i += 1
                else:
                    ans.append((i,j))
                    i += 1
            return ans
        nums.sort()
        ans = set()
        for i in range(len(nums)-2):
            for j,k in twoSum(i+1,len(nums)-1,-nums[i]):
                ans.add((nums[i],nums[j],nums[k]))
        return list(ans)



        