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
vector<int> inorder;
void inorderTraversal(TreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    inorder.push_back(root->val);
    inorderTraversal(root->right);
}
public:
    bool findTarget(TreeNode* root, int k) 
    {
        inorderTraversal(root);
        int n = inorder.size();
        int left = 0;
        int right = n-1;
        while(left < right)
        {
            if(inorder[left] + inorder[right] == k)
            {
                return true;
            }
            if(inorder[left] + inorder[right] < k)
            {
                left++;
            }
            if(inorder[left] + inorder[right] > k)
            {
                right--;
            }
        }
        return false;
    }
};
