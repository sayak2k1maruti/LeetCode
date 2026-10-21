class Solution:
    def minOperations(self, s: str) -> int:
        if all(s[i] <= s[i+1] for i in range(len(s) - 1)):
            return 0
        elif len(s) == 2:
            return -1
        cmin,cmax = min(s),max(s)
        if s[0] == cmin or s[-1] == cmax:
            return 1
        
        if s[0] == cmax and s[-1] == cmin and cmin not in s[1:-1] and cmax not in s[1:-1]:
            return 3
            
        return 2