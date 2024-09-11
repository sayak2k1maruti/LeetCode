BIT_LEN = 32
class Solution:
    def match_bits(self,n,bit_arr):
        i = 0
        while n:
            bit_arr[i] ^= n%2
            n = n>>1
            i+=1
    
    def minBitFlips(self, start: int, goal: int) -> int:
        bit_arr = [0] * BIT_LEN
        self.match_bits(start,bit_arr)
        self.match_bits(goal,bit_arr)
        return bit_arr.count(1)
        