class Solution:
    def candy(self, ratings: list[int]) -> int:
        n = len(ratings)
        arr = [1]*n
        def check(i):
            left,right = 0,0
            if i+1<n and ratings[i+1] < ratings[i] and arr[i] <=arr[i+1]:
                right = arr[i+1]
            if i-1>=0 and ratings[i-1] < ratings[i] and arr[i] <= arr[i-1]:
                left = arr[i-1]
            if left or right:
                return max(right,left) + 1
            return arr[i]    
        
        for i in range(n):
            arr[i] = check(i)
        for i in range(n):
            arr[n-1-i] = check(n-i-1)


        return sum(arr)

        