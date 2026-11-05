class Solution:
    def hIndex(self, citations: list[int]) -> int:
        citations.sort()
        for i in range(1,len(citations)+1):
            if citations[-i] < i:
                return i-1
        return min(citations[0],len(citations))


