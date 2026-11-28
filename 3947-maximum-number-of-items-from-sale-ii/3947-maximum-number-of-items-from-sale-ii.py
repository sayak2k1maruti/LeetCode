class Solution:
    def maximumSaleItems(self, items: List[List[int]], budget: int) -> int:
        n = len(items)
        maxf = max(f for f, _ in items)
        freq = [0] * (maxf + 1)
        for f, _ in items:
            freq[f] += 1
        div_count = [0] * (maxf + 1)
        for f in range(1, maxf + 1):
            s = 0
            for k in range(f, maxf + 1, f):
                s += freq[k]
            div_count[f] = s
        slots = [(p, div_count[f] - 1) for f, p in items]
        slots.sort()
        p_min = slots[0][0]

        count = 0
        for price, K in slots:
            if price > 2 * p_min:
                break                        
            d = min(K, budget // price)      
            count += 2 * d
            budget -= d * price
        count += budget // p_min             
        return count