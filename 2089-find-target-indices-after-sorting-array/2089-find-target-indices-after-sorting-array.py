class Solution:
    def targetIndices(self, nums: list[int], target: int) -> list[int]:
        smaller = 0
        count = 0
        for n in nums:
            if n < target:
                smaller += 1
            elif n == target:
                count += 1  
        if count:
            return [smaller + i for i in range(count)]
        return []
        
        