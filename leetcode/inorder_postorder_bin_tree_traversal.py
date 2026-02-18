# Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

# Example 1:
# Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
# Output: [3,9,20,null,null,15,7]
# logic:
# 1) find last elem in postorder -> its the root
# 2) recursively split inorder based on found root elem
# 3) continue splitting until all nodes are visited

from typing import List, Optional, Dict


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        ind_inorder = {val: i for i, val in enumerate(inorder)}
        self.post_idx = len(postorder) - 1
    
        def helperFunc(in_left, in_right):
            if in_left > in_right:
                return None
            
            val = postorder[self.post_idx]
            root = TreeNode(val)
            self.post_idx -= 1
            index = ind_inorder[val]
            
            root.right = helperFunc(index + 1, in_right)
            root.left = helperFunc(in_left, index - 1)
            
            return root
        
        return helperFunc(0, len(inorder) - 1)