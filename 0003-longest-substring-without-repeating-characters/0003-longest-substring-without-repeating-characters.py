class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i,j = 0,0
        used = set()
        ans = 0
        while j < len(s):
            if i>j:
                used.clear()
                j=i
                continue
            if s[j] not in used:
                used.add(s[j])
            else:
                ans = max(ans,j-i)
                while i < j:
                    if s[i] != s[j]:
                        used.remove(s[i])
                        i+=1
                    else:
                        break
                i+=1
            j+=1
        return max(ans,j-i)
            
