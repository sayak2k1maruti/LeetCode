class Solution:
    def insert(self, intervals: list[list[int]], newInterval: list[int]) -> list[list[int]]:
        indx = 0
        while indx < len(intervals):
            start,end = intervals[indx]
            if newInterval[0] < start:
                break
            indx+=1
        intervals = intervals[:indx] + [newInterval] + intervals[indx:]

        merged_intervals = []
        start_merged,end_merged = intervals[0]
        for i in range(1,len(intervals)):
            start,end = intervals[i]
            if end_merged >= start:
                end_merged = max(end_merged,end)
            else:
                merged_intervals.append([start_merged,end_merged])
                start_merged,end_merged = start,end
        merged_intervals.append([start_merged,end_merged])
        return merged_intervals
            