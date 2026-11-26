class Solution:
    def canAliceWin(self, n: int,c:int=10) -> bool:
        if c>n:
            return bool(c%2 & 1)
        return self.canAliceWin(n-c,c-1)