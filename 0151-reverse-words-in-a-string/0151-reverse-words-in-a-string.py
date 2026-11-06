class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(reversed([i for i in s.strip().split(' ') if i]))