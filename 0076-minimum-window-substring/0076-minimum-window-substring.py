from collections import Counter
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        ct = Counter(t)
        ns, nt =  len(s), len(t)
        ans = (0,ns,ns+1)
        check_len = 0
        i,j = 0,0
        while j< ns or check_len == nt:
            if check_len < nt:
                if s[j] in ct:
                    ct[s[j]] -= 1
                    if ct[s[j]] >=0:
                        check_len += 1
                j+=1
            elif check_len == nt:
                if (j-i) < ans[2]:
                    ans = (i,j,j-i)
                if s[i] in ct:
                    ct[s[i]] += 1
                    if ct[s[i]] >0:
                        check_len -= 1
                i+=1


        if ans[2] < ns+1:
            return s[ans[0]:ans[1]]
        return ''

