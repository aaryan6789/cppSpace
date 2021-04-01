from Tree._tree_ import *
from collections import deque, defaultdict

def verticalOrder(root):
    """
    :type root: TreeNode
    :rtype: List[List[int]]
    """
    
    if not root:
        return []

    map = defaultdict(list)
    q = deque()
    
    q.append([root, 0])
    
    while q:
        temp = q.popleft()
        
        tnode = temp[0]
        hd = temp[1]
        
        if tnode is not None:
            map[hd].append(tnode.val)
            
            q.append((tnode.left, hd-1))
            q.append((tnode.right, hd+1))
    
    vertO = []
    for x in sorted(map.keys()):
        vertO.append(map[x])
        
    return vertO