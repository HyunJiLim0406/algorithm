# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findRoot(self, hasParent: List[int], roots: List[int]):
        for root in roots:
            if root not in hasParent:
                return root

    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        tree = {}
        hasParent = []

        for parent, child, isLeft in descriptions:
            hasParent.append(child)
            
            if (parent not in tree):
                tree[parent] = TreeNode(parent)
            if (child not in tree):
                tree[child] = TreeNode(child)
            
            if (isLeft == 1):
                tree[parent].left = tree[child]
            else:
                tree[parent].right = tree[child]

        root = self.findRoot(hasParent, [sublist[0] for sublist in descriptions])
        return tree[root]