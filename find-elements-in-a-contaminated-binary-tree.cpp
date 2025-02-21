/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
private:
    TreeNode* root;  // Store the root of the recovered tree

    void recover(TreeNode* node) {
        if (!node) return;

        if (node->left) {
            node->left->val = 2 * node->val + 1;
            recover(node->left);
        }
        
        if (node->right) {
            node->right->val = 2 * node->val + 2;
            recover(node->right);
        }
    }

    bool search(TreeNode* node, int target) {
        if (!node) return false;
        if (node->val == target) return true;
        return search(node->left, target) || search(node->right, target);
    }

public:
    FindElements(TreeNode* root) {
        this->root = root;
        if (root) {
            root->val = 0;
            recover(root);
        }
    }

    bool find(int target) {
        return search(root, target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
