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
                    ans.append((nums[i],nums[j]))
                    i += 1
                    j-=1
                    while i < j and nums[i] == nums[i - 1]:   
                            i += 1 #skip dups
            return ans
        nums.sort()
        ans = []
        for i in range(len(nums)-2):
            if i > 0 and nums[i] == nums[i-1]:
                continue #skipping same search
            for b,c in twoSum(i+1,len(nums)-1,-nums[i]):
                ans.append((nums[i],b,c))
        return ans



        