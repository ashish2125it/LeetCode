# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def populate_parent_map(self, root, parent_map):
        if not root:
            return
        
        if root.left:
            parent_map[root.left] = root
            self.populate_parent_map(root.left, parent_map)
        if root.right:
            parent_map[root.right] = root
            self.populate_parent_map(root.right, parent_map)

    def distanceK(self, root: TreeNode, target: TreeNode, k: int):
        parent_map = {}
        self.populate_parent_map(root, parent_map)  # Populate the parent map.

        q = deque([target])
        visited = {target: True}
        current_distance = 0

        # Perform BFS to find nodes at distance k.
        while q:
            if current_distance == k:
                break  # Stop when the desired distance is reached.

            for i in range(0,len(q),1):
                node = q.popleft()
                
                # Explore neighbors: left, right, and parent.
                if node.left and node.left not in visited:
                    q.append(node.left)
                    visited[node.left] = True

                if node.right and node.right not in visited:
                    q.append(node.right)
                    visited[node.right] = True

                if parent_map.get(node) and parent_map[node] not in visited:
                    q.append(parent_map[node])
                    visited[parent_map[node]] = True
                    


            
            current_distance += 1

        # Collect all nodes at distance k.
        return [node.val for node in q]
