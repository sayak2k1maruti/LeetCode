BIT_LEN = 32
class Solution:
    def count_set_bits(self,n):
        count = 0
        while n:
            count += n%2
            n = n>>1
        return count
    def minBitFlips(self, start: int, goal: int) -> int:
        return self.count_set_bits(start ^ goal)
        