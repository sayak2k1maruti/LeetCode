class Solution:
    def smallestUniqueSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        MOD, BASE = (1 << 61) - 1, 131
        
        h = [0] * (n + 1)
        p = [1] * (n + 1)
        for i, x in enumerate(nums):
            h[i + 1] = (h[i] * BASE + x) % MOD
            p[i + 1] = (p[i] * BASE) % MOD
        
        def has_unique(L):
            counts = {}
            for i in range(n - L + 1):
                hv = (h[i + L] - h[i] * p[L]) % MOD
                counts[hv] = counts.get(hv, 0) + 1
            return any(c == 1 for c in counts.values())
        
        lo, hi, ans = 1, n, n
        while lo <= hi:
            mid = (lo + hi) // 2
            if has_unique(mid):
                ans = mid
                hi = mid - 1
            else:
                lo = mid + 1
        return ans