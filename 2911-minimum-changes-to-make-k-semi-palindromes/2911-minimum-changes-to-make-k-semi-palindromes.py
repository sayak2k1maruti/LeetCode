class Solution:
    _cache = {}
    _cachePrdm = {}
    _cahceMinimumChanges = {}
    def makePdrm(self,s) -> int:
        if s in self._cachePrdm:
            return self._cachePrdm[s]
        self._cachePrdm[s] =  sum(s[c] != s[~c] for c in range(len(s)//2))
        # print(f"makePalindrm({s}) --> {ans}")
        return self._cachePrdm[s]

    def makeSemiPdrm(self, s) -> int:
        if s in self._cache:
            return self._cache[s]
        minChange = float('inf')
        for d in range(1, len(s)//2 + 1 , 1):
            if len(s)%d:
                continue
            groups = [[] for _ in range(d)]
            for i, ch in enumerate(s):
                groups[i % d].append(ch)
            groups =  [''.join(g) for g in groups]
            change = sum(self.makePdrm(subS) for subS in groups)
            minChange = min(change,minChange)
            if minChange == 0:
                break
        # print(f"MinChange({s}) -> {minChange}")
        self._cache[s] = minChange; return minChange
        
    def minimumChanges(self, s: str, k: int) -> int:
        if (s,k) in self._cahceMinimumChanges:
            return self._cahceMinimumChanges[(s,k)]
        if k == 1:
            return self.makeSemiPdrm(s)
        
        if len(s) < 2*k:
            return float('inf')

        minChange = float('inf')
        for i in range(2,len(s) - 2*(k-1) + 1):
            minChange = min(
                minChange,
                self.makeSemiPdrm(s[:i]) + self.minimumChanges(s[i:],k-1)
            ) 
        self._cahceMinimumChanges[(s,k)] =  minChange; return self._cahceMinimumChanges[(s,k)]
        
        
