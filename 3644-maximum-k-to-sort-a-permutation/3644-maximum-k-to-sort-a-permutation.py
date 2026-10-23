import operator
class Solution:
    def sortPermutation(self, nums: List[int]) -> int:
        ans = reduce(operator.and_,(i for i,n in enumerate(nums) if i!=n),-1)
        return ans if ans != -1 else 0
        