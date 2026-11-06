class Solution:
    def convert(self, s: str, numRows: int) -> str:
        ans = []
        if numRows >= len(s):
            return s
        if numRows == 1:
            return s
        if len(s) <= 2:
            return s
        chunk = numRows + numRows - 2
        for i in range(numRows):
            j = i
            while j < len(s):
                ans.append(s[j])
                if i not in (0,numRows-1):
                    if j + chunk - 2 * i  < len(s):
                        ans.append(s[j + chunk - 2 * i ])
                j += chunk
        return ''.join(ans)