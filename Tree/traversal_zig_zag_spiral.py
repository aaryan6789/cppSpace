"""
/* LeetCode M 103 | CTCI
 * ZIG ZAG Traversal
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values.
 * (ie, from left to right, then right to left for the next level and alternate
 * between).
 *
 * For example: Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
 *
 * return its zigzag level order traversal as:
 *
 * [
 *   [3],
 *   [20,9],
 *   [15,7]
 * ]
 */
 """
# /* Algorithm: Using 2 stacks
#  * 1. Use one stack for printing from left to right and
#  *    other stack for printing from right to left.
#  * 2. In every iteration, we have nodes of one level in one of the stacks.
#  * 3. Print the nodes, and push nodes of next level in other stack.
#  */
import collections

from _tree_ import *
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


def zigzagLevelOrder(root):
    """
    :type root: TreeNode
    :rtype: List[List[int]]
    """
    levels = []
    if not root:
        return levels
    
    odd = collections.deque()
    even = collections.deque()
    
    odd.append(root)
    
    while odd or even:
        level = []
        while odd:
            temp = odd.popleft()
            level.append(temp.val)
            
            if temp.left:
                even.appendleft(temp.left)
                
            if temp.right:
                even.appendleft(temp.right)
        
        levels.append(level)
        level = []
        
        while even:
            temp = even.popleft()
            level.append(temp.val)
            
            if temp.right:
                odd.appendleft(temp.right)
            
            if temp.left:
                odd.appendleft(temp.left)
        
        if len(level) > 0:             
            levels.append(level)
    
    return levels