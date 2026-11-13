from collections import defaultdict
class Solution:
    def containsNearbyDuplicate(self, nums: list[int], k: int) -> bool:
        mapp = defaultdict(list)
        for i in range(len(nums)):
            if mapp[nums[i]]:
                if any(abs(i-j)<=k for j in mapp[nums[i]]):
                    return True
            mapp[nums[i]].append(i)
        return False

        
