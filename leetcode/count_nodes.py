"""
Given the root of a complete binary tree, return the number of the nodes in the tree.
According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
Design an algorithm that runs in less than O(n) time complexity.
"""

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
# class Solution:
#     def countNodes(self, root: Optional[TreeNode]) -> int:
#         if not root: 
#             return
        
#         deque = [root]
#         count = 1
        
#         while deque:
#             node = deque.pop()
#             if node.left:
#                 deque.append(node.left)
#                 count += 1
#             if node.right:
#                 deque.append(node.right)
#                 count += 1
                
#         return count

class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        """
        @brief: Calculates the number of nodes in a complete binary tree.
        @params: root (Optional[TreeNode]): The root node of the complete binary tree.
        @returns: int: The total number of nodes in the tree.
        
        This algorithm leverages the properties of a complete binary tree to achieve 
        sub-linear time complexity by comparing the heights of the leftmost and 
        rightmost paths.
        """
        
        if not root:
            return 0
        
        left_h = self._get_height_left(root)
        right_h = self._get_height_right(root)
        
        if left_h == right_h:
            return (2 ** left_h) - 1
        
        return 1 + self.countNodes(root.left) + self.countNodes(root.right)
    
    def _get_height_left(self, node: Optional[TreeNode]) -> int:
        height = 0
        
        while node:
            height += 1
            node = node.left
            
        return height
    
    def _get_height_right(self, node: Optional[TreeNode]) -> int:
        height = 0
        
        while node:
            height += 1
            node = node.right
            
        return height