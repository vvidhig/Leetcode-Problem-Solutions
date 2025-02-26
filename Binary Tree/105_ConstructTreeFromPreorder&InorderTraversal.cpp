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
    TreeNode* treeFormation(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& mp)
    {
        if(preStart>preEnd || inStart>inEnd)
        {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = mp[root->val];
        int numsleft = inRoot - inStart;
        root->left = treeFormation(preorder, preStart+1, preStart+numsleft, inorder, inStart, inRoot-1, mp);
        root->right = treeFormation(preorder, preStart+numsleft+1, preEnd, inorder, inRoot+1, inEnd, mp);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        unordered_map<int, int> mp;
        int n = preorder.size()-1;
        for(int i = 0; i<=n; i++)
        {
            mp[inorder[i]] = i;
        }
        TreeNode* root = treeFormation(preorder, 0, n, inorder, 0, n, mp);
        return root;
    }
};
