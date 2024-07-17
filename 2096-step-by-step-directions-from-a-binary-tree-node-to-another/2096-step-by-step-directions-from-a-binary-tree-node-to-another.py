# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.found = False

    def dfs(self, node: TreeNode, target: int, curPath: []):
        if node.val == target:
            self.found = True
            return curPath

        if not self.found and node.left:
            curPath.append('L')
            self.dfs(node.left, target, curPath)
            if not self.found:
                curPath.pop()
        if not self.found and node.right:
            curPath.append('R')
            self.dfs(node.right, target, curPath)
            if not self.found:
                curPath.pop()
        return curPath

    def getPath(self, startPath: [], destPath: []) -> str:
        while min(len(startPath), len(destPath)) > 0 and startPath[0] == destPath[0]:
            startPath.pop(0)
            destPath.pop(0)
        startPath = 'U' * len(startPath)

        return startPath + ''.join(destPath)

    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
        startPath = self.dfs(root, startValue, [])
        self.found = False
        destPath = self.dfs(root, destValue, [])

        return self.getPath(startPath, destPath)
        