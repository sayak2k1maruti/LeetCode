class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        n = min(len(s) for s in strs)
        ans= []
        for i in range(n):
            c = strs[0][i]
            if all(s[i] == c for s in strs):
                ans.append(c)
                continue
            break
        return ''.join(ans)

        
        