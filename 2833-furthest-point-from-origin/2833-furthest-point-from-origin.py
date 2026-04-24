from collections import Counter
class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        d = Counter(moves)
        return d["L"] - d["R"] + d["_"] if d["L"] > d["R"] else d["R"] - d["L"] + d["_"]

        