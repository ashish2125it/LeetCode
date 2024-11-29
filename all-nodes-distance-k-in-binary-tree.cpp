class Solution {
public:
    void populateParentMap(TreeNode* root, map<TreeNode*, TreeNode*>& parentMap) {
        if (!root) return;

        if (root->left) {
            parentMap[root->left] = root;
            populateParentMap(root->left, parentMap);
        }
        if (root->right) {
            parentMap[root->right] = root;
            populateParentMap(root->right, parentMap);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> parentMap;
        populateParentMap(root, parentMap); // Populate the parent map.

        queue<TreeNode*> q;
        map<TreeNode*, bool> visited;
        q.push(target);
        visited[target] = true;

        int currentDistance = 0;

        // Perform BFS to find nodes at distance k.
        while (!q.empty()) {
            int size = q.size();
            if (currentDistance == k) break; // Stop when the desired distance is reached.

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Explore neighbors: left, right, and parent.
                if (node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if (node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if (parentMap[node] && !visited[parentMap[node]]) {
                    q.push(parentMap[node]);
                    visited[parentMap[node]] = true;
                }
            }

            currentDistance++;
        }

        // Collect all nodes at distance k.
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
    }
};
