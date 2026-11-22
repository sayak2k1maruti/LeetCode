class Solution:
    def checkString(self, s: str) -> bool:
        a = None
        b = None
        for i in range(len(s)-1,-1,-1):
            if s[i] == 'a':
                a = i
                break
        for i in range(len(s)):
            if s[i] == 'b':
                b = i
                break
        if a is not None and b is not None:
            return b > a
        return True
        