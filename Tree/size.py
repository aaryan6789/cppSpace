
from Tree._tree_ import TreeNode

def sizeOfTree(root):
    if root is None:
        return 0

    return 1 + sizeOfTree(root.left) + sizeOfTree(root.right)