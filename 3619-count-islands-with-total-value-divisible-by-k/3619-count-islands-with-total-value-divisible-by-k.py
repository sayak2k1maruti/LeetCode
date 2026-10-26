class Solution:
    def countIslands(self, grid: List[List[int]], k: int) -> int:
        m,n = len(grid), len(grid[0])
        visited = [[False]*n for _ in range(m)]
        def checkncount(i,j):
            if i<0 or j<0 or i>m-1 or j>n-1:
                return 0
            if visited[i][j] or not grid[i][j]:
                return 0
            visited[i][j] = True
            return grid[i][j] + checkncount(i+1,j)+checkncount(i-1,j)+checkncount(i,j+1)+checkncount(i,j-1)
        ans = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] and not visited[i][j]:
                    count = checkncount(i,j)
                    if not (count % k):
                        ans += 1
        return ans

        