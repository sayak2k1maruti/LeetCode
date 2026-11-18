class Solution:
    def minChanges(self, s: str) -> int:
        return sum(p!=n for p,n in zip(s[::2],s[1::2]))