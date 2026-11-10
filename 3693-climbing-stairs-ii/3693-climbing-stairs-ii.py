class Solution:
    # dp = {}
    # def climb(self,n,costs,i):
    #     if i in self.dp:
    #         return self.dp[i]
    #     if i>=n-1:
    #         return 0
    #     lowest = float('inf')
    #     for j in range(i+1,i+4):
    #         if j >= n:
    #             break
    #         lowest = min(lowest,self.climb(n,costs,j)+costs[j]+(j-i)**2)
    #     self.dp[i] = lowest; return self.dp[i]

    def climbStairs(self, n: int, costs: List[int]) -> int:
        # self.dp = {}
        # return self.climb(n,costs,-1)

        minCosts = [0]*(n+1)
        for i in range(n-1,-1,-1):
            minCosts[i] = min(minCosts[j]+costs[j-1]+(j-i)**2 for j in range(i+1,min(i+4,n+1)))
        return minCosts[0]

        