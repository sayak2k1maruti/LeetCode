from queue import Queue 
class Solution:
    def jump(self, nums: list[int]) -> int:
        if len(nums) <= 1:
            return 0
        q = Queue()
        q.put(0)
        q.put(None)
        depth = 0
        n = len(nums)
        visited = set()
        while not q.empty():
            depth += 1
            while True:
                index = q.get()
                if index == None:
                    break
                if index + nums[index] >= n-1:
                    return depth
                for i in range(index+1,index+1+nums[index]):
                    if i not in visited:
                        q.put(i)
                        visited.add(i)
            if not q.empty():
                q.put(None)
            
        return depth
            
        
        