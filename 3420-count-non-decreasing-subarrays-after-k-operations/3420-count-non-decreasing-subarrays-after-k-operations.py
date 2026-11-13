from collections import deque

class Solution:
    def countNonDecreasingSubarrays(self, nums: List[int], k: int) -> int:
        nums = nums[::-1]
        n = len(nums)
        i,j = 0,0
        diff = 0
        count = 0
        dq = deque()
        while j<n:
            cnt = 1
            while dq and dq[-1][0] < nums[j]:
                v,c = dq.pop()
                diff += (nums[j] - v) * c
                cnt += c
            dq.append([nums[j], cnt])
            while diff>k:
                diff -= dq[0][0] - nums[i]
                dq[0][1] -= 1
                if dq[0][1]==0:
                    dq.popleft()
                i+=1
            count += j-i+1
            j+=1
        return count