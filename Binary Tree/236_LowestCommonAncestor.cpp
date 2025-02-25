/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path)
    {
        if(root==NULL)
        {
            return false;
        }
        path.push_back(root);
        if(root == target)
        {
            return true;
        }
        if(findPath(root->left, target, path) || findPath(root->right, target, path))
        {
            return true;
        }
        path.pop_back();
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        findPath(root, p, path1);
        findPath(root, q, path2);
        TreeNode* common;
        int n = min(path1.size(), path2.size());
        for(int i = 0; i<n; i++)
        {
            if(path1[i] == path2[i])
            {
                common = path1[i];
            }
            else
            {
                break;
            }
        }
        return common;
    }
};
