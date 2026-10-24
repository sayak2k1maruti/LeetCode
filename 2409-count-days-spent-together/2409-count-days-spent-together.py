import datetime
class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        arrive_alice = datetime.date.strptime(f"{arriveAlice}-2026","%m-%d-%Y")
        leave_alice = datetime.date.strptime(f"{leaveAlice}-2026","%m-%d-%Y")
        arrive_bob = datetime.date.strptime(f"{arriveBob}-2026","%m-%d-%Y")
        leave_bob = datetime.date.strptime(f"{leaveBob}-2026","%m-%d-%Y")
        leave = min(leave_bob,leave_alice)
        arrive = max(arrive_alice, arrive_bob)
        if arrive <= leave:
            return (leave-arrive).days + 1
        else:
            return 0
