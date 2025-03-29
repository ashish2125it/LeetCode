# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
        
    def solve(self, root, start, path, res):
        if not root:
            return
        
        if root.val == start:
            res.append(path[:])
            return
        
        path.append('L')
        self.solve(root.left, start, path, res)
        path.pop()
        
        path.append('R')
        self.solve(root.right, start, path, res)
        path.pop()
        
    def getDirections(self, root: TreeNode, startValue: int, destValue: int) -> str:
        path1, path2 = [], []
        self.solve(root, startValue, [], path1)
        self.solve(root, destValue, [], path2)
        
        s1, s2 = path1[0], path2[0]
        
        i = 0
        while i < len(s1) and i < len(s2) and s1[i] == s2[i]:
            i += 1
        
        t1 = 'U' * (len(s1) - i)
        t2 = ''.join(s2[i:])
        
        return t1 + t2
