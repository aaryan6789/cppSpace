from Tree._tree_ import TreeNode

def isSameTree(p: TreeNode, q) -> bool:
    if p is None and q is None:
        return True
    
    if p is None or q is None:
        return False
    
    if p.val!= q.val:
        return False
    
    if p.val==q.val:
        return(isSameTree(p.left,q.left) and isSameTree(p.right,q.right))