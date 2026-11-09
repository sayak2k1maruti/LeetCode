from collections import Counter
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        ct = Counter(t)
        i = 0
        ns, nt =  len(s), len(t)
        ct_copy = dict(ct)
        ans = (0,ns,ns+1)
        check_len = 0
        i,j = 0,0
        while j< ns or check_len == nt:
            if check_len < nt:
                if s[j] in ct_copy:
                    ct_copy[s[j]] -= 1
                    if ct_copy[s[j]] >=0:
                        check_len += 1
                j+=1
            elif check_len == nt:
                if (j-i) < ans[2]:
                    ans = (i,j,j-i)
                if s[i] in ct_copy:
                    ct_copy[s[i]] += 1
                    if ct_copy[s[i]] >0:
                        check_len -= 1
                i+=1


        if ans[2] < ns+1:
            return s[ans[0]:ans[1]]
        return ''

