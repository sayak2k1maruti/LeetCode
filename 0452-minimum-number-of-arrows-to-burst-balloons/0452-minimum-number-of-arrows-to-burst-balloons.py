class Solution:
    def findMinArrowShots(self, points: list[list[int]]) -> int:
        points.sort(key=lambda x: x[1])
        e = points[0][1]
        arrow = 1
        for i in range(1,len(points)):
            if points[i][0] <= e:
                e = min(e,points[i][1])
            else :
                arrow += 1
                e = points[i][1]
        return arrow