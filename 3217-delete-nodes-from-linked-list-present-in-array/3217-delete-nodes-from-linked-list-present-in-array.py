# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        numSet, before, pointer = set(nums), None, head
        while pointer:
            if pointer.val in numSet:
                if before == None:
                    head = head.next
                else:
                    before.next = pointer.next
            else:
                before = pointer
            pointer = pointer.next
        return head