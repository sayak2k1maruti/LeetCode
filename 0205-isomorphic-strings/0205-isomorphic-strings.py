class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        char_map = {}
        values = set()
        for i in range(len(s)):
            if s[i] in char_map:
                if char_map[s[i]] != t[i]:
                    return False
            elif t[i] in values:
                return False
            char_map[s[i]] = t[i]
            values.add(t[i])
        return True