from operator import ne
class Solution:
    def minChanges(self, s: str) -> int:
        return sum(map(ne,s[::2],s[1::2]))