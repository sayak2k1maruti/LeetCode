class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        open_close = {
            '{' : '}',
            '(' : ')',
            '[' : ']'
        }
        for c in s:
            if c in open_close:
                stack.append(c)
            elif stack and open_close[stack[-1]] == c:
                stack.pop()
            else :
                return False
        return False if stack else True