class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        int n = d.size();
        if (n == 0) return NULL;
        
        unordered_map<int, TreeNode*> mp;  // Map to store nodes by their values
        unordered_set<int> children;  // Set to track all child nodes
        TreeNode* root = NULL;
        
        // First pass: build nodes and track children
        for (int i = 0; i < n; i++) {
            int parent = d[i][0];
            int child = d[i][1];
            int left_child = d[i][2];
            
            // Create or fetch parent and child nodes
            if (mp.find(parent) == mp.end()) {
                mp[parent] = new TreeNode(parent);
            }
            if (mp.find(child) == mp.end()) {
                mp[child] = new TreeNode(child);
            }
            
            
            if (left_child) {
                mp[parent]->left = mp[child];
            } else {
                mp[parent]->right = mp[child];
            }
            
            
            children.insert(child);
        }
        
       
        for (auto& entry : mp) {
            if (children.find(entry.first) == children.end()) {
                root = entry.second;  // This is the root
                break;
            }
        }
        
        return root;
    }
};
