class Solution:
    def candy(self, ratings: list[int]) -> int:
        n = len(ratings)
        candy = [1]*n
        # def check(i):
        #     left,right = 0,0
        #     if i+1<n and ratings[i+1] < ratings[i] and candy[i] <=candy[i+1]:
        #         right = candy[i+1]
        #     if i-1>=0 and ratings[i-1] < ratings[i] and candy[i] <= candy[i-1]:
        #         left = candy[i-1]
        #     if left or right:
        #         return max(right,left) + 1
        #     return candy[i]    
        
        for i in range(1,n):
            if i-1>=0 and ratings[i-1] < ratings[i] and candy[i] <= candy[i-1]:
                candy[i] = candy[i-1] + 1

        
        for i in range(n-2,-1,-1):
            if i+1<n and ratings[i+1] < ratings[i] and candy[i] <=candy[i+1]:
                candy[i] = candy[i+1] + 1


        return sum(candy)

        