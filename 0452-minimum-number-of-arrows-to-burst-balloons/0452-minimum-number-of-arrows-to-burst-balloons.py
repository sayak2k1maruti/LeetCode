class Solution:
    def findMinArrowShots(self, points: list[list[int]]) -> int:
        points.sort(key=lambda x: x[1])
        e_p = points[0][1]
        arrow = 1
        for s,e in points[1:]:
            if s > e_p:
                arrow += 1
                e_p = e
        return arrow