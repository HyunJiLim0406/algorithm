# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        levelSum = {}
        queue = [(root, 0)]
        
        while queue:
            node, level = queue.pop(0)
            levelSum[level] = levelSum.get(level, 0) + node.val
            if node.left:
                queue.append((node.left, level + 1))
            if node.right:
                queue.append((node.right, level + 1))
        sortedLevel = sorted(levelSum.values(), reverse=True)
        return sortedLevel[k - 1] if k <= len(sortedLevel) else -1
        