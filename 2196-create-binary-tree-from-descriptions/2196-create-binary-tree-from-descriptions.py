# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def buildTree(self, descriptions: List[List[int]]):
        tree = {} #key: node, value: {left, right, parent}
        for parent, child, isLeft in descriptions:
            if parent not in tree:
                tree[parent] = [None, None, None]
            tree[parent][isLeft ^ 1] = child
            if child in tree:
                tree[child][2] = parent
            else:
                tree[child] = [None, None, parent]
        return tree

    def findRoot(self, start: int, tree: {}):
        root = start
        while(tree[root][2]):
            root = tree[root][2]
        return root
    
    def getTreeNode(self, root: int, tree: {}):
        result = TreeNode(root)
        queue = [(result, root)]

        while(len(queue) != 0):
            node, idx = queue.pop(0)            
            treeValue = tree[node.val]
            
            if(treeValue[0]):
                node.left = TreeNode(treeValue[0])
                queue.append((node.left, treeValue[0]))
            else:
                node.left = None

            if(treeValue[1]):
                node.right = TreeNode(treeValue[1])
                queue.append((node.right, treeValue[1]))
            else:
                node.right = None
        return result

    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        tree = self.buildTree(descriptions)
        return self.getTreeNode(self.findRoot(descriptions[0][0], tree), tree)
        