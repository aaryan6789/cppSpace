#!/usr/bin/env python3
# from Tree._tree_ import TreeNode, printListsList
from Tree._tree_ import *
from Tree.maxDepth import *
from Tree.same_tree import isSameTree
from Tree.traversal_level_order import levelOrder
from Tree.traversal_vertical_order import verticalOrder
from Tree.size_of_tree import mySize
from Tree import size

def main():
    print("Tree 2020")
    root = TreeNode(10)
    root.left = TreeNode(20)
    root.right = TreeNode(30)

    root.left.left = TreeNode(40)
    root.left.right = TreeNode(50)

    root.right.left = TreeNode(60)
    root.right.right = TreeNode(70)

    sz = size.sizeOfTree(root)
    sz = mySize(root)
    print("Size of the Tree = ", sz)

    depth = maxDepth(root)
    print("Depth of the Tree = ", depth)

    depth = maxDepth1(root)
    print("Depth of the Tree = ", depth)

    res = isSameTree(root, root)
    print ("Is the Tree Same ", res)

    lvlO = levelOrder(root)
    print("Level Order Traversal - Line by Line")
    printListsList(lvlO)

    vo = verticalOrder(root)
    print("Vertical Order Traversal")
    printListsList(vo)

if __name__ == "__main__":
    main()