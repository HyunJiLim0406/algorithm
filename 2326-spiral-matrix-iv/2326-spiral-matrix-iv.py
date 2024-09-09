# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isValid(self, m: int, n: int, row: int, col: int):
        return 0 <= row < m and 0 <= col < n

    def spiralMatrix(self, m: int, n: int, head: Optional[ListNode]) -> List[List[int]]:
        matrix = [[-1 for _ in range(n)] for _ in range(m)]
        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        row, col, idx = 0, 0, 0
        
        while head:
            matrix[row][col] = head.val
            nRow, nCol = row + dirs[idx][0], col + dirs[idx][1]
            if not self.isValid(m, n, nRow, nCol) or matrix[nRow][nCol] != -1:
                idx = (idx + 1) % 4
            row += dirs[idx][0]
            col += dirs[idx][1]
            head = head.next
        return matrix
