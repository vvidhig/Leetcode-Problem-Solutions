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
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        int n = preorder.size();
        if(n==0)
        {
            return NULL;
        }
        stack<TreeNode*> st;
        TreeNode* root = new TreeNode(preorder[0]);
        st.push(root);
        for(int i = 1; i<n; i++)
        {
            TreeNode* node = new TreeNode(preorder[i]);
            TreeNode* parent = NULL;
            
            while(!st.empty() && st.top()->val < preorder[i])
            {
                parent = st.top();
                st.pop();
            }
            if(parent)
            {
                parent->right = node;
            }
            else
            {
                st.top()->left = node;
            }
            st.push(node);
        }
        return root;
    }
};
