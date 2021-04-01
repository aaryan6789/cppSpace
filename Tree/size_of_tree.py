from Tree._tree_ import TreeNode

def mySize(root):
    if root is None:
        return 0

    return 1 + mySize(root.left) + mySize(root.right)