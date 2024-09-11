BIT_LEN = 32
class Solution:
    @staticmethod
    def count_set_bits(n):
        count = 0
        while n:
            count += n%2
            n = n>>1
        return count
    def minBitFlips(self, start: int, goal: int) -> int:
        return Solution.count_set_bits(start ^ goal)
        