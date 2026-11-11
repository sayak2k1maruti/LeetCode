class Solution:
    def minimumCost(self, cost1: int, cost2: int, costBoth: int, need1: int, need2: int) -> int:
        if costBoth > cost1 + cost2:
            return need1*cost1 + need2*cost2
        if need2<need1:
            need1,need2 = need2,need1
            cost1,cost2 = cost2,cost1
        return min(need1*costBoth + (need2-need1)*cost2, need2*costBoth)