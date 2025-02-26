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
    int leftHeight(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int cnt = 0;
        while(root)
        {
            root = root->left;
            cnt+=1;
        }
        return cnt;
    }
    int rightHeight(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int cnt = 0;
        while(root)
        {
            root = root->right;
            cnt+=1;
        }
        return cnt;
    }
    public:
    int countNodes(TreeNode* root) 
    {
        int lh = leftHeight(root);
        int rh = rightHeight(root);
        if(lh==rh)
        {
            return pow(2, lh)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
