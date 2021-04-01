from Tree import _tree_

def maxDepth1(root):
    if root is None:
        return 0

    return 1 + max(maxDepth1(root.left), maxDepth1(root.right))

def maxDepth(root):
    """
    :type root: TreeNode
    :rtype: int
    """ 
    stack = []
    if root is not None:
        stack.append((1, root))
    
    depth = 0
    while stack != []:
        current_depth, root = stack.pop()
        if root is not None:
            depth = max(depth, current_depth)
            stack.append((current_depth + 1, root.left))
            stack.append((current_depth + 1, root.right))
    
    return depth