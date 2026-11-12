class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        mapp = {}
        values = set()
        words = s.split(' ')
        if len(words) != len(pattern):
            return False
        for a,b in zip(pattern,s.split()):
            if a in mapp:
                if mapp[a] != b:
                    return False
            elif b in values:
                return False
            mapp[a] = b
            values.add(b)
        return True