from collections import deque
from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    # Helper function to find the node with the given value (start)
    def findNode(self, root: TreeNode, start: int) :
        if not root:
            return None
        if root.val == start:
            return root

        # Recursively search in left and right subtrees
        left = self.findNode(root.left, start)
        if left:
            return left
        return self.findNode(root.right, start)

    # Helper function to map each node to its parent
    def mapParents(self, root: TreeNode, parent_map: dict):
        if not root:
            return
        
        # If left child exists, store its parent and recurse
        if root.left:
            parent_map[root.left] = root
            self.mapParents(root.left, parent_map)

        # If right child exists, store its parent and recurse
        if root.right:
            parent_map[root.right] = root
            self.mapParents(root.right, parent_map)

    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        if not root:
            return 0

        # Step 1: Find the node where infection starts
        start_node = self.findNode(root, start)
        if not start_node:
            return 0
        
        # Step 2: Create a mapping of each node to its parent
        parent_map = {}
        self.mapParents(root, parent_map)
        
        # Step 3: Perform BFS traversal to calculate infection spread time
        visited = set()  # Set to keep track of visited nodes
        q = deque([start_node])  # Queue for BFS traversal
        visited.add(start_node)
        
        time = 0  # To keep track of time taken to infect the whole tree
        
        while q:
            size = len(q)
            for _ in range(size):
                node = q.popleft()  # Get the current node

                # Spread infection to the left child if it exists and is not visited
                if node.left and node.left not in visited:
                    q.append(node.left)
                    visited.add(node.left)

                # Spread infection to the right child if it exists and is not visited
                if node.right and node.right not in visited:
                    q.append(node.right)
                    visited.add(node.right)

                # Spread infection to the parent node if it exists and is not visited
                if node in parent_map and parent_map[node] not in visited:
                    q.append(parent_map[node])
                    visited.add(parent_map[node])
            
            # Increase time after processing each level of infection spread
            if q:  # Ensure time is incremented only if there are more nodes to process
                time += 1

        return time  # Return the total time taken to infect the entire tree
