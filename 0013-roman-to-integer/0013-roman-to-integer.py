class Solution:
    def romanToInt(self, s: str) -> int:
        values = {
            'I' : 1,
            'V' : 5,
            'X' : 10,
            'L' : 50,
            'C' : 100,
            'D' : 500,
            'M' : 1000
        }
        num = 0
        for i in range(len(s)):
            digit = values[s[i]]
            if i<len(s)-1 and values[s[i]] < values[s[i+1]]:
                    digit  *= -1
            num += digit
        return num

# 1000 - 100 + 1000 - 10 + 100 - 1 + 5