class Solution:
    def findMinArrowShots(self, points: list[list[int]]) -> int:
        points.sort(key=lambda x: x[1])
        e_p = -float('inf')
        arrow = 0
        for s,e in points:
            if s > e_p:
                arrow += 1
                e_p = e
        return arrow