class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        ans = []
        for i,j in zip(nums[:n],nums[n:]):
            ans.append(i)
            ans.append(j)
        return ans