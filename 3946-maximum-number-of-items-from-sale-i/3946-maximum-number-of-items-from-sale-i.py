class Solution:
    def maximumSaleItems(self, items: List[List[int]], budget: int) -> int:
        n = len(items)
        g = [0] * n
        for i in range(n):
            fi = items[i][0]
            for j in range(n):
                if i != j and items[j][0] % fi == 0:
                    g[i] += 1

        dp = [[[-1] * (budget + 1) for _ in range(n + 1)] for _ in range(2)]
        def rec(i: int, rem: int, bought: int) -> int:
            if i == n:
                return 0
            if dp[bought][i][rem] != -1:
                return dp[bought][i][rem]
            best = rec(i + 1, rem, 0)
            price = items[i][1]
            if price <= rem:
                gain = 1 + (0 if bought else g[i])
                cand = gain + rec(i, rem - price, 1)
                if cand > best:
                    best = cand

            dp[bought][i][rem] = best
            return best

        return rec(0, budget, 0)