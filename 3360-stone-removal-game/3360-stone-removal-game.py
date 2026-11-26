class Solution:
    def canAliceWin(self, n: int,c:int=10) -> bool:
        return self.canAliceWin(n-c,c-1) if c<=n else bool(c&1)