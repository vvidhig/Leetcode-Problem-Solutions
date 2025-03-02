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
private:
    void inorderTraversal(TreeNode* root, vector<int>& inorder)
    {
        if(root == NULL)
        {
            return;
        }
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }
public:
    bool isValidBST(TreeNode* root) 
    {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        int n = inorder.size();
        for(int i = 0; i<n-1; i++)
        {
            if(inorder[i] >= inorder[i+1])
            {
                return false;
            }
        }
        return true;
    }
};
