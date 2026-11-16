import heapq
class Solution:
    def findKthLargest(self, nums: list[int], k: int) -> int:
        ans = []
        for n in nums:
            heapq.heappush(ans,n)
            if len(ans)>k:
                heapq.heappop(ans)
        return heapq.heappop(ans)