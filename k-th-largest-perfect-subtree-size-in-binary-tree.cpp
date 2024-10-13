class Solution {
    vector<int> ans;

    vector<int> solve(TreeNode* root) {
        if (!root) {
            return {0, 0, 1}; // {node count, height, is perfect}
        }

        vector<int> left = solve(root->left);
        vector<int> right = solve(root->right);

        // Check if both left and right subtrees are perfect and of the same height
        if (left[2] == 1 && right[2] == 1 && left[1] == right[1]) {
            ans.push_back(1 + left[0] + right[0]);
        }

        // Current subtree properties
        vector<int> current(3);
        current[0] = 1 + left[0] + right[0]; // Total node count
        current[1] = 1 + max(left[1], right[1]); // Height
        current[2] = (left[2] == 1 && right[2] == 1 && left[1] == right[1]) ? 1 : 0; // Is perfect

        return current;
    }

public:
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        solve(root);
        sort(ans.rbegin(), ans.rend());
        if (k <= ans.size()) {
            return ans[k - 1]; 
        }
        return -1;
    }
};
