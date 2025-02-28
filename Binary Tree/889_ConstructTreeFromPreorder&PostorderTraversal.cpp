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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) 
    {
        unordered_map<int, int> postIndex;
        int n = preorder.size()-1;
        for(int i = 0; i<=n; i++)
        {
            postIndex[postorder[i]] = i;
        }
        int index = 0;
        return buildTree(preorder, index, postorder, 0, n, postIndex);
    }
    TreeNode* buildTree(vector<int>& preorder, int& index, vector<int>& postorder, int poststart, int postend, unordered_map<int, int>& postIndex)
    {
        if(index >= preorder.size() || poststart > postend)
        {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[index++]);
        if(poststart == postend)
        {
            return root;
        }
        int leftRoot = preorder[index];
        int leftSubtree = postIndex[leftRoot];
        root->left = buildTree(preorder, index, postorder, poststart, leftSubtree, postIndex);
        root->right = buildTree(preorder, index, postorder, leftSubtree+1, postend-1, postIndex);
        return root;
    }
};
