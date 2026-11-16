class Solution:
    def merge(self, intervals: list[list[int]]) -> list[list[int]]:
        intervals.sort()
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