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
    int widthOfBinaryTree(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 0;
        }
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        long long pos;
        int maxwidth = INT_MIN;
        while(q.size()>0)
        {
            int size = q.size();
            long long left = q.front().second;
            long long right = q.back().second;
            maxwidth = max(maxwidth, (int)(right-left+1));
            for(int i = 0; i<size; i++)
            {
                auto p = q.front();
                q.pop();
                TreeNode* node = p.first;
                pos = p.second;
                if(node->left != NULL)
                {
                    q.push({node->left, 2*pos});
                }
                if(node->right != NULL)
                {
                    q.push({node->right, 2*pos+1});
                }
            }
        }
        return maxwidth;
    }
};
