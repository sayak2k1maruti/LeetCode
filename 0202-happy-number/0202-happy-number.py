def digitSq(n):
    if not n:
        return 0
    return (n%10)**2 + digitSq(n//10)

class Solution:
    def isHappy(self, n: int) -> bool:
        used = set()
        while n not in used:
            used.add(n)
            if n==1:
                return True
            n = digitSq(n)
            print(n)
        return False