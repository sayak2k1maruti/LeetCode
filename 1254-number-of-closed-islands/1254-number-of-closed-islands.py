class Solution:
    def closedIsland(self, grid: list[list[int]]) -> int:
        m,n = len(grid),len(grid[0])
        visited = [[False] * n for _ in range(m)]
        def found_water(i,j):
            if i<0 or j<0:
                return False
            elif i>m-1 or j > n-1: 
                return False
            if visited[i][j]:
                return True
            if grid[i][j] == 1:
                return True
            visited[i][j] = True
            return all((
                found_water(i,j+1),
                found_water(i,j-1),
                found_water(i+1,j),
                found_water(i-1,j),
                # found_water(i+1,j+1),
                # found_water(i+1,j-1),
                # found_water(i-1,j+1),
                # found_water(i-1,j-1)
            )
            )
        count = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0 and not visited[i][j]:
                    if found_water(i,j):
                        count += 1
        return count
