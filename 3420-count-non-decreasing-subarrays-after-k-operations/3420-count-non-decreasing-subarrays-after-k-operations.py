from collections import deque

class Solution:
    def countNonDecreasingSubarrays(self, nums: List[int], k: int) -> int:
        n = len(nums)
        i, j = n - 1, n - 1
        diff = 0
        count = 0
        blocks = deque()  

        while i >= 0:
            cnt = 1
            while blocks and blocks[-1][0] < nums[i]:
                v, c = blocks.pop()
                diff += (nums[i] - v) * c
                cnt += c
            blocks.append([nums[i], cnt])

            while diff > k:
                diff -= blocks[0][0] - nums[j]
                blocks[0][1] -= 1
                if blocks[0][1] == 0:
                    blocks.popleft()
                j -= 1

            count += j - i + 1  
            i -= 1
        return count