class Solution:
    def isPalindrome(self, s: str) -> bool:
        def check(c):
            if c >= 'a' and c <= 'z':
                return True
            elif c >= '0' and c <= '9':
                return True
            return False

        n = len(s)
        l,r = 0,n-1
        s = s.lower()
        while l<r:
            if not check(s[l]):
                l+= 1
                continue
            elif not check(s[r]):
                r-=1
                continue
            elif s[l].lower() != s[r].lower():
                return False
            l+=1
            r-=1
        return True