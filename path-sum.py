from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    # Helper function to check if there is a root-to-leaf path with sum equal to targetSum
    def solve(self, root, targetSum) :
        if not root:
            return False

        # If it's a leaf node, check if the remaining sum equals node's value
        if not root.left and not root.right:
            return targetSum == root.val

        # Recursively check left and right subtrees with updated sum
        left = self.solve(root.left, targetSum - root.val)
        right = self.solve(root.right, targetSum - root.val)

        return left or right

    # Main function to determine if a path with targetSum exists
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root:
            return False

        return self.solve(root, targetSum)
