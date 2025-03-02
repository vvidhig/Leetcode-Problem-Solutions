class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        TreeNode* newVal = new TreeNode(val);
        if(root==NULL)
        {
            return newVal;
        }
        TreeNode* curr = root;
        TreeNode* join = root;
        while(curr!=NULL)
        {
            if(curr!=NULL && curr->val < val)
            {
                join = curr;
                curr = curr->right;
            }
            if(curr!=NULL && curr->val > val)
            {
                join = curr;
                curr = curr->left;
            }
        }
        if(join->val > val)
        {
            join->left = newVal;
        }
        else
        {
            join->right = newVal;
        }
        return root;
    }
};
