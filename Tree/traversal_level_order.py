from Tree._tree_ import TreeNode

def levelOrder(root):
    """
    :type root: TreeNode
    :rtype: List[List[int]]
    """
    if not root: 
        return root
    
    queue = []
    queue.append(root)
    levels = []
    
    while queue: 
        cur_level = []
        size = len(queue)
        for i in range(size):
            node = queue.pop(0)
            cur_level.append(node.val)
            if node.left:
                queue.append(node.left)
        
            if node.right:
                queue.append(node.right)
        
        levels.append(cur_level)
    
    print("Haha")
    return levels


def levelOrder2(root):
    """
    :type root: TreeNode
    :rtype: List[List[int]]
    """
    res = []
    if not root:
        return res
    
    q = collections.deque()
    q.append(root)
    
    while q:
        nc = len(q)
        
        level = []
        while nc > 0:
            temp = q.popleft()
            level.append(temp.val)
        
            if temp.left:
                q.append(temp.left)
            
            if temp.right:
                q.append(temp.right)
            
            nc -= 1
        
        res.append(level)
    
    return res