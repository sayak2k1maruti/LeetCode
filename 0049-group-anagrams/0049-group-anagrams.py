from collections import defaultdict
class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        mapp = defaultdict(list)
        for s in strs:
            s_sorted = "".join(sorted(s))
            mapp[s_sorted].append(s)
        return list(mapp.values())