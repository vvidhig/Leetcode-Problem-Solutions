/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    // Step 1: Build Parent Mapping
    void buildParentMap(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_map) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                parent_map[node->left] = node;  // Store parent
                q.push(node->left);
            }
            if (node->right) {
                parent_map[node->right] = node; // Store parent
                q.push(node->right);
            }
        }
    }

    // Step 2: Find Target Node & Perform BFS to Find Nodes at Distance K
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root) return {};  // Edge case: Empty tree
        
        unordered_map<TreeNode*, TreeNode*> parent_map;  // Node → Parent Mapping
        buildParentMap(root, parent_map);
        
        unordered_set<TreeNode*> visited;  // To avoid revisiting nodes
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);
        
        int level = 0;
        while (!q.empty()) {
            if (level == k) break; // Stop BFS at level k
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Explore left child
                if (node->left && visited.find(node->left) == visited.end()) {
                    q.push(node->left);
                    visited.insert(node->left);
                }
                // Explore right child
                if (node->right && visited.find(node->right) == visited.end()) {
                    q.push(node->right);
                    visited.insert(node->right);
                }
                // Explore parent
                if (parent_map.find(node) != parent_map.end() && visited.find(parent_map[node]) == visited.end()) {
                    q.push(parent_map[node]);
                    visited.insert(parent_map[node]);
                }
            }
            level++;
        }

        // Step 3: Collect Nodes at Distance K
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
    }
};
