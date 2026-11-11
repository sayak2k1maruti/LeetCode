from collections import Counter
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        mp = Counter(magazine)
        def check(c):
            if c in mp and mp[c]>0:
                mp[c]-=1
                return True
            return False
        return all(check(c) for c in ransomNote)