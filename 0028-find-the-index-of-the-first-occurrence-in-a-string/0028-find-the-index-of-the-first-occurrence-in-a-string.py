class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        for i in range(len(haystack) - len(needle) + 1):
            flag = True
            for j in range(len(needle)):
                if needle[j] != haystack[i+j]:
                    flag = False
                    break
            if flag:
                return i
        return -1


        