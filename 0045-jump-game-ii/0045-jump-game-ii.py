from collections import deque 
class Solution:
    def jump(self, nums: list[int]) -> int:
        if len(nums) <= 1:
            return 0
        q = deque()
        q.append(0)
        q.append(None)
        depth = 0
        n = len(nums)
        visited = set()
        while q:
            depth += 1
            while True:
                index = q.popleft()
                if index is None:
                    break
                if index + nums[index] >= n-1:
                    return depth
                for i in range(index+1,index+1+nums[index]):
                    if i not in visited:
                        q.append(i)
                        visited.add(i)
            if q:
                q.append(None)
            
        return depth
            
        
        