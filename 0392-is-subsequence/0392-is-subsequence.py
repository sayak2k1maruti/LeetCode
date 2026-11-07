class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        nt = len(t)
        ns = len(s)
        i,j = 0,0
        while j < ns and i < nt:
            if t[i] == s[j]:
                j += 1
            i += 1
        return j >= ns

        