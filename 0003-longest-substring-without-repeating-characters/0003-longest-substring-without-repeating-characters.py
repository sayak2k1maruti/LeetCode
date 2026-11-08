class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i,j = 0,0
        used = set()
        ans = 0
        for j in range(len(s)):
            if s[j] not in used:
                ans = max(ans,j-i+1)  
                used.add(s[j])
                continue
            while s[i] != s[j]:
                used.remove(s[i])
                i+=1
            i+=1
        
        return max(ans,j-i)
            
