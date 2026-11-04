class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        # n = len(prices)
        # maxArr = [0]*n #maximum price till now
        # maxP = prices[-1]
        # for i in range(1,n+1):
        #     if prices[-i] > maxP:
        #         maxP = prices[-i]
        #     maxArr[-i] = maxP

        # ans = 0 #max profit
        # for i in range(n):
        #     profit = maxArr[i] - prices[i]
        #     if profit > ans:
        #         ans= profit
        # return ans
        minSellPrice = prices[0]
        maxProfit = 0
        for price in prices:
            maxProfit = max(maxProfit,price - minSellPrice)
            minSellPrice = min(minSellPrice,price)
        return maxProfit



