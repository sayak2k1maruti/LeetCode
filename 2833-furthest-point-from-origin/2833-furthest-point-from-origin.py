from collections import Counter
class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        d = Counter(moves)
        return abs(d["L"] - d["R"]) + d["_"]

        