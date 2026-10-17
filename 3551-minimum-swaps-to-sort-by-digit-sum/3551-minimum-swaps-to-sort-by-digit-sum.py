def digitSum(n):
    sum = 0
    while n > 0:
        sum+= n%10
        n //= 10
    return sum   
class Solution:


    def minSwaps(self, nums: List[int]) -> int:
        arr = [(digitSum(i),i) for i in nums]
        indx_map = {nums[i] : i for i in range(len(nums))}
        sorted_arr = sorted(arr)
        # print(arr)
        # print(sorted_arr)

        swap = 0
        for i in range(len(arr)):
            if arr[i][1] != sorted_arr[i][1]:
                swap+=1
                indx = indx_map[sorted_arr[i][1]]
                arr[indx] = arr[i]
                arr[i] = sorted_arr[i]
                indx_map[arr[i][1]] = i
                indx_map[arr[indx][1]] = indx
            # print(arr)
        return swap

            
        