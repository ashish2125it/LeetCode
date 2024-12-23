class Solution {
public:
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> temp;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // To count the minimum swaps to sort the 'temp' vector
            vector<pair<int, int>> sorted_temp;
            for (int i = 0; i < temp.size(); i++) {
                sorted_temp.push_back({temp[i], i});
            }

            sort(sorted_temp.begin(), sorted_temp.end());

            // Cycle detection for minimum swaps
            vector<bool> visited(temp.size(), false);
            for (int i = 0; i < sorted_temp.size(); i++) {
                if (visited[i] || sorted_temp[i].second == i) {
                    continue; // Already sorted or visited
                }

                int cycle_size = 0;
                int j = i;

                // Traverse the cycle
                while (!visited[j]) {
                    visited[j] = true;
                    j = sorted_temp[j].second;
                    cycle_size++;
                }

                if (cycle_size > 1) {
                    ans += (cycle_size - 1); // Swaps needed for this cycle
                }
            }
        }

        return ans;
    }
};
