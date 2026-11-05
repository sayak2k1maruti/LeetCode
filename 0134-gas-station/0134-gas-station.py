class Solution:
    def canCompleteCircuit(self, gas: list[int], cost: list[int]) -> int:
        if sum(gas) < sum(cost):
            return -1
        n = len(gas)
        failed = -1
        for start in range(n):
            if start<=failed:
                continue
            tank = 0
            for k in range(n-start):
                i = (start + k) % n
                tank += gas[i] - cost[i]
                if tank < 0:
                    failed = i
                    break
            else:
                return start

        return -1



        