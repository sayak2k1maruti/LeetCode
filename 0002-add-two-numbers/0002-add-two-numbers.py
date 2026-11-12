# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode | None, l2: ListNode | None) -> ListNode | None:
        carry = 0
        head = None
        curr = None
        while l1 or l2 or carry:
            a = l1.val if l1 else 0
            b = l2.val if l2 else 0
            s =  a + b + carry
            l = ListNode(s%10)
            if head is None:
                head = curr =l
            else:
                curr.next = l
                curr = curr.next
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
            carry = s//10
        return head

            