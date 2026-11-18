class Solution:
    def findMinArrowShots(self, points: list[list[int]]) -> int:
        points.sort()
        s,e = points[0]
        arrow = 1
        for i in range(1,len(points)):
            if points[i][0] <= e:
                e = min(e,points[i][1])
            else :
                arrow += 1
                s,e = points[i]
        return arrow