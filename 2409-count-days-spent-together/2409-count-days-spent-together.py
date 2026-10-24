from datetime import date

class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        arrive = max(arriveAlice, arriveBob)
        leave = min(leaveAlice, leaveBob)
        
        if arrive > leave:
            return 0
        
        d1 = date.fromisoformat(f"2026-{arrive}")
        d2 = date.fromisoformat(f"2026-{leave}")
        
        return (d2 - d1).days + 1