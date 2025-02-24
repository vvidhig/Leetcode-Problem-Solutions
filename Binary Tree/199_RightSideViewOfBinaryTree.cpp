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
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> ans;
        if(root==NULL)
        {
            return ans;
        }
        queue<pair<TreeNode*, int>> q;
        map<int, int> mp;
        q.push({root, 0});
        while(q.size()>0)
        {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int row = p.second;
            if(node!=NULL)
                mp[row] = node->val;
            if(node->left!=NULL)
            {
                q.push({node->left, row+1});
            }
            if(node->right!=NULL)
            {
                q.push({node->right, row+1});
            }
        }
        for(auto p : mp)
        {
            ans.push_back(p.second);
        }
        return ans;
    }
};
