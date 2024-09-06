# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        numSet = set()
        numSet.update(nums)
        before = None
        pointer = head
        while pointer.next:
            if pointer.val in numSet:
                if before == None:
                    pointer = head.next
                    head = head.next
                else:
                    before.next = pointer.next
                    pointer = pointer.next
            else:
                before = pointer
                pointer = pointer.next
        if pointer.val in nums:
            before.next = None
        return head