class Solution:
    def insert(self, intervals: list[list[int]], newInterval: list[int]) -> list[list[int]]:
        s,e = newInterval
        left = [it for it in intervals if it[1]<s]
        right = [it for it in intervals if it[0]>e]

        
        if len(left) + len(right) != len(intervals):
            s = min(s,intervals[len(left)][0])
            e = max(e,intervals[-len(right)-1][-1] )
        return left + [[s,e]] + right
        
        