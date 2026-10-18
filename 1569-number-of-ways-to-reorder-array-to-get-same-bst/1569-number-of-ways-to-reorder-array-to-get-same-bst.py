import math
MOD = 10**9 + 7
MAX = 1000

fact = [1]*(MAX+1)
for i in range(1,MAX+1):
    fact[i] = i*fact[i-1]%MOD

def ways(nums):
    if len(nums) < 3:
        return 1
    root = nums[0]
    left,right  = [],[]
    for i in nums[1:]:
        if i < root:
            left.append(i)
        else:
            right.append(i)
    
    r = max(len(right),len(left))
    # comb =  fact[len(nums)-1] // (fact[len(nums)-1-r] * fact[r])
    comb = fact[len(nums)-1] * pow(fact[len(nums)-1-r], MOD - 2, MOD)  *  pow(fact[r], MOD - 2, MOD) % MOD
    return comb * ways(left) * ways(right) % MOD
    #return math.comb(len(nums) - 1,max(len(left),len(right))) * ways(left) * ways(right) % MOD

class Solution:
    def numOfWays(self, nums: list[int]) -> int:
        return ways(nums) - 1