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
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) 
    {
        if(traversal.empty()) return NULL;

        stack<TreeNode*> st;
        int i = 0, n = traversal.length();

        while(i < n)
        {
            int depth = 0;
            // Count depth using '-'
            while(i < n && traversal[i] == '-')
            {
                depth++;
                i++;
            }

            // Extract node value (handle multi-digit)
            int nodeVal = 0;
            while(i < n && isdigit(traversal[i]))
            {
                nodeVal = nodeVal * 10 + (traversal[i] - '0');
                i++;
            }

            TreeNode* node = new TreeNode(nodeVal);

            // Ensure stack size matches depth
            while (st.size() > depth) 
            {
                st.pop();
            }

            // Attach node to parent
            if (!st.empty()) 
            {
                if (!st.top()->left) 
                {
                    st.top()->left = node;
                } 
                else 
                {
                    st.top()->right = node;
                }
            }

            // Push new node to stack
            st.push(node);
        }

        // Get root node
        while (st.size() > 1) 
        {
            st.pop();
        }
        return st.top();
    }
};
