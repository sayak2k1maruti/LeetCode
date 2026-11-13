cache = {}
def digitSq(n):
    if n in cache:
        return cache[n]
    if not n:
        return 0
    cache[n] = (n%10)**2 + digitSq(n//10); return cache[n]

class Solution:
    def isHappy(self, n: int) -> bool:
        used = set()
        while n not in used:
            used.add(n)
            if n==1:
                return True
            elif n<4:
                return False
            n = digitSq(n)
        return False