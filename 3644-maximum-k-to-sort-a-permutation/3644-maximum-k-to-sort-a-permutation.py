import operator
MAX = 2**64 - 1
class Solution:
    def sortPermutation(self, nums: List[int]) -> int:
        ans = MAX
        ans = reduce(operator.and_,(i for i,n in enumerate(nums) if i!=n),-1)
        return ans if ans != -1 else 0
        