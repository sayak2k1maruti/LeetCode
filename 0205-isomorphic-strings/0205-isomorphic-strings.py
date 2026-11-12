class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        char_map = {}
        values = set()
        for a,b in zip(s,t):
            if a in char_map:
                if char_map[a] != b:
                    return False
            elif b in values:
                return False
            char_map[a] = b
            values.add(b)
        return True