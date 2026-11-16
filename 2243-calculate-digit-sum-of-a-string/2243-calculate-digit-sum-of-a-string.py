from functools import reduce
import operator

class Solution:
    def digit_sum_str(self, s, start, end) -> str:
        # Calculate Digit Sum
        return str(sum(ord(s[i])-ord('0') for i in range(start,end)))
        
    def newS(self, s, k) -> str:
        # Returns the new string
        new_string_list = [
            self.digit_sum_str(s,i,min(i+k, len(s)))
            for i in range(0,len(s),k)
        ]
        return "".join(new_string_list)

    def digitSum(self, s: str, k: int) -> str:
        if len(s) <= k:
            return s
        return self.digitSum(self.newS(s,k),k)