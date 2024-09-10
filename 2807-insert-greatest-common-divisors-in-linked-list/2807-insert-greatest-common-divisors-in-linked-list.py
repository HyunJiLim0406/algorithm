import math

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        pointer = head
        while pointer.next:
            a, b = pointer.val, pointer.next.val
            gcd = math.gcd(a, b)
            pointer.next = ListNode(gcd, pointer.next)
            pointer = pointer.next.next
        return head

        